#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""Tritech Micron serial communication handler."""

import serial
import bitstring
from tritech_micron.replies import Reply
from tritech_micron.commands import Command
from tritech_micron.exceptions import PacketIncomplete

__author__ = "Anass Al-Wohoush, Jana Pavlasek, Malcolm Watt, Vincent Schiller"


class Socket(object):

    """Serial communication socket.

    Attributes:
        conn: Serial connection.
    """

    def __init__(self, port, node):
        """Constructs Socket object.

        Args:
            port: Serial port.
        """
        self.node = node
        self.conn = serial.Serial(port=port, baudrate=115200)
        
    def open(self):
        """Opens serial connection."""
        self.node.get_logger().info("Open serial conection...")
        self.conn.open()
        self.node.get_logger().info("Conection is open!")

    def close(self):
        """Closes serial connection."""
        self.conn.close()

    def send(self, message, payload=None):
        """Formats message and payload into packet and sends it to device.

        Args:
            command: Command to send.
            payload: Additional payload to send in packet.
        """
        cmd = Command(message, payload)        
        self.conn.write(cmd.serialize())     

    def get_reply(self):
        """Waits for and returns Reply.

        Returns:
            First complete reply if expected message ID was not specified,
            otherwise first complete reply of expected message ID.

        Raises:
            PacketCorrupted: Packet is corrupt.
        """
        try:
            # Wait for the '@' character.            
            while not self.conn.read() == b'@':                
                pass

            # Read one line at a time until packet is complete and parsed.
            packet = bitstring.BitStream("0x40")
            while True:
                # Read until new line.
                current_line = self.conn.readline()
                hex_values = [f"0x{byte:02x}" for byte in current_line]                
                for hex_value in hex_values:
                    packet.append(hex_value)
                # Try to parse.
                try:
                    reply = Reply(packet)
                    break
                except PacketIncomplete:
                    # Keep looking.
                    continue

            self.node.get_logger().debug(f"Received {reply.name}: {reply.payload}") 
            return reply
        except KeyboardInterrupt:
            self.node.get_logger().info("KeyboardInterrupt received, shutting down")
            raise
        except Exception as e:  # Catch more general exceptions
            self.node.get_logger().debug(f"Error in get_reply: {e}")