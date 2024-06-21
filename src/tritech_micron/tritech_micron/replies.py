#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Tritech Micron replies."""

from tritech_micron.messages import Message
from bitstring import ReadError
from tritech_micron.exceptions import PacketIncomplete, PacketCorrupted

__author__ = "Erin Havens, Jey Kumar, Anass Al-Wohoush, Vincent Schiller"


class Reply(object):

    """Parses and verifies reply packets.

    Attributes:
        id: Message ID.
        name: Message ID human-readable name.
        is_last: Whether packet is last in sequence.
        payload: Data excluding header and end character.
        sequence: Packet sequence.
        size: Number of bytes in packet from 6th byte onwards.
    """

    def __init__(self, bitstream):
        """Constructs Reply object.

        Args:
            bitstream: BitStream holding packet to parse.

        Raises:
            PacketIncomplete: Packet is incomplete.
            PacketCorrupted: Packet is corrupted.
        """
        self.bitstream = bitstream

        self.id = 0
        self.name = "<unknown>"
        self.is_last = False
        self.payload = None
        self.sequence = 0
        self.size = 0

        self.parse()

    def __str__(self):
        """Returns string representation of reply."""
        return "<msg: {s.id}, {s.size} bytes, '0x{s.bitstream.hex}'>".format(
            s=self
        )

    def parse(self):
        """Parses packet into header, message ID, sequence and payload.

        This method also checks if the packet contains all relevant fields and
        has the correct size.

        Raises:
            PacketIncomplete: Packet is incomplete.
            PacketCorrupted: Packet is corrupted.
        """
        try:
            # Parse message header and check for line feed.
            self.bitstream.bytepos = 0
            if self.bitstream.endswith("0x0A"):
                header = self.bitstream.read("uint:8")
            else:
                raise PacketIncomplete("Packet does not end with line feed")

            # Verify message header is '@'.
            if header != 0x40:
                raise PacketCorrupted("Unexpected header: {}".format(header))

            # Find package Hex Length from byte 6, excluding LF
            # as it is noted in packet bytes 2-5.
            self.bitstream.bytepos = 1
            hex_list = [self.bitstream.read("hex:8") for i in range(4)]
            ascii_string = ''.join((chr(int(i, 16)) for i in hex_list))
            self.size = int(ascii_string, 16)     
           
            # Check if the size of the packet is correct,
            # by comparing packet's real size to self.size.
            real_size = (self.bitstream.len / 8) - 6  # 6 bytes
            if real_size < self.size:
                self.node.get_logger().error("Packet is undersize: {} / {} Packet: {}".format(
                    real_size, self.size, self.bitstream))
            elif real_size > self.size:
                self.node.get_logger().error("Packet is oversize: {} / {} Packet: {}".format(
                    real_size, self.size, self.bitstream))       

            # Check if Bin Length equals Hex Length.
            # Note we read num as little-endian unsigned int.
            self.bitstream.bytepos = 5
            bin_ln = self.bitstream.read("uintle:16")
            if bin_ln != self.size:
                raise PacketCorrupted(
                    "Binary and hex size mismatch: bin: {}, hex: {}"
                    .format(bin_ln, self.size)
                )

            # Parse Packet Source Identification Node.
            self.bitstream.bytepos = 7
            source_id = self.bitstream.read("uint:8")

            # Check Packet Destination Identification Node is 255.
            self.bitstream.bytepos = 8
            dest_id = self.bitstream.read("uint:8")
            if dest_id != 255:
                raise PacketCorrupted(
                    "Invalid Packet Destination Identification Node: {}"
                    .format(dest_id)
                )

            # Parse message ID and verify it's between 0-72.
            self.bitstream.bytepos = 10
            self.id = self.bitstream.read("uint:8")
            self.name = Message.to_string(self.id)
            if not 0 <= self.id <= 72:
                raise PacketCorrupted("Invalid message ID: {}".format(self.id))

            # Check for size following byte 10, excluding LF.
            self.bitstream.bytepos = 9
            byte_count = self.bitstream.read("uint:8")
            if self.id == Message.HEAD_DATA and byte_count == 0:
                # HEAD_DATA single-packet replies are different; always 0.
                # Could be used to confirm whether it's in single-packet mode.
                pass
            else:
                # For all other replies, verify size.
                # Byte count differs from self.size by 5 bytes.
                if byte_count != self.size - 5:
                    raise PacketCorrupted(
                        "Bytes left mismatch: recv: {}, exp: {}, id: {}"
                        .format(byte_count, self.size - 5, self.id)
                    )

            # Parse message sequence bitset.
            self.bitstream.bytepos = 11
            self.is_last = self.bitstream.read("bool")
            self.sequence = self.bitstream.read("uint:7")

            # Read bitset to determine number of packets.
            # Necessary for Multi-packet mode.
            pass

            # Verify TX Node number. Should be equal to Packet Source
            # Identification Node number.
            self.bitstream.bytepos = 12
            tx_node = self.bitstream.read("uint:8")
            if tx_node != source_id:
                raise PacketCorrupted(
                    "Node number mismatch: TX: {}, Source ID: {}"
                    .format(tx_node, source_id)
                )

            # Parse message payload (byte 14 to end, excluding LF).
            self.bitstream.bytepos = 13
            size_payload = (self.size - 8) * 8
            self.payload = self.bitstream.read(size_payload)
        except (ValueError, ReadError) as e:
            raise PacketCorrupted("Unexpected error", e)