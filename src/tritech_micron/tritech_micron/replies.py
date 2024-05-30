#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Tritech Micron replies."""

from tritech_micron.messages import Message
from bitstring import ReadError
from tritech_micron.exceptions import PacketIncomplete, PacketCorrupted

__author__ = "Erin Havens, Jey Kumar, Anass Al-Wohoush"


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

    def __init__(self, byte_array):
        """Constructs Reply object.

        Args:
            byte_array: Bytearray holding packet to parse.

        Raises:
            PacketIncomplete: Packet is incomplete.
            PacketCorrupted: Packet is corrupted.
        """
        self.byte_array = byte_array

        self.id = 0
        self.name = "<unknown>"
        self.is_last = False
        self.payload = None
        self.sequence = 0
        self.size = 0

        self.parse()

    def parse(self):
        """Parses packet into header, message ID, sequence and payload.

        This method also checks if the packet contains all relevant fields and
        has the correct size.

        Raises:
            PacketIncomplete: Packet is incomplete.
            PacketCorrupted: Packet is corrupted.
        """
        try:
            # Verify message header is '@'.
            if self.byte_array[0] != 0x40:
                raise PacketCorrupted("Unexpected header: {}".format(self.byte_array[0]))

            # Find package Hex Length from byte 6, excluding LF
            # as it is noted in packet bytes 2-5.
            hex_list = [self.byte_array[i] for i in range(1, 5)]            
            hex_string = ''.join('{:02X}'.format(byte) for byte in hex_list)
            self.size = int(bytes.fromhex(hex_string).decode("ascii"), 16)
            
            # Check if the size of the packet is correct,
            # by comparing packet's real size to self.size.
            real_size = len(self.byte_array) - 6  # 6 bytes
            if real_size < self.size:
                raise PacketIncomplete(
                    "Packet is undersize: {} / {}"
                    .format(real_size, self.size)
                )
            elif real_size > self.size:
                raise PacketCorrupted(
                    "Packet is oversize: {} / {}"
                    .format(real_size, self.size)
                )

            # Check if Bin Length equals Hex Length.
            # Note we read num as little-endian unsigned int.
            bin_ln = int.from_bytes(self.byte_array[5:7], byteorder='little')
            if bin_ln != self.size:
                raise PacketCorrupted(
                    "Binary and hex size mismatch: bin: {}, hex: {}"
                    .format(bin_ln, self.size)
                )

            # Parse Packet Source Identification Node.
            source_id = self.byte_array[6]

            # Check Packet Destination Identification Node is 255.
            dest_id = self.byte_array[7]
            if dest_id != 255:
                raise PacketCorrupted(
                    "Invalid Packet Destination Identification Node: {}"
                    .format(dest_id)
                )

            # Parse message ID and verify it's between 0-72.
            self.id = self.byte_array[9]
            self.name = Message.to_string(self.id)
            if not 0 <= self.id <= 72:
                raise PacketCorrupted("Invalid message ID: {}".format(self.id))

            # Check for size following byte 10, excluding LF.
            byte_count = self.byte_array[8]
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
            self.is_last = self.byte_array[10] != 0
            self.sequence = self.byte_array[11]

            # Read bitset to determine number of packets.
            # Necessary for Multi-packet mode.
            pass

            # Verify TX Node number. Should be equal to Packet Source
            # Identification Node number.
            tx_node = self.byte_array[12]
            if tx_node != source_id:
                raise PacketCorrupted(
                    "Node number mismatch: TX: {}, Source ID: {}"
                    .format(tx_node, source_id)
                )

            # Parse message payload (byte 14 to end, excluding LF).
            self.payload = self.byte_array[13:]
        except (ValueError, ReadError) as e:
            raise PacketCorrupted("Unexpected error", e)
