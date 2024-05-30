#!/usr/bin/env python3

"""Tritech Micron serial communication handler."""

import errno
import serial
import select
import bitstring
from tritech_micron.replies import Reply
from tritech_micron.messages import Message
from tritech_micron.commands import Command
from tritech_micron.exceptions import PacketIncomplete, PacketCorrupted
from tritech_micron.serial_readline import SerialReadline

__author__ = "Anass Al-Wohoush, Jana Pavlasek, Malcolm Watt, Vincent Schiller"

class Socket(object):
    """Serial communication socket.

    Attributes:
        conn: Serial connection.
        readConn: SerialReadline object for efficient line reading.
    """

    def __init__(self, port, node):
        """Constructs Socket object.

        Args:
            port: Serial port.
        """
        self.conn = serial.Serial(
            port='/dev/ttyUSB0',
            baudrate=115200,  
            parity=serial.PARITY_NONE,
            stopbits=serial.STOPBITS_ONE,
            bytesize=serial.EIGHTBITS,
            timeout=1
        )
        self.readConn = SerialReadline(self.conn, node)
        self.node = node

    def open(self):
        """Opens serial connection."""
        self.conn.open()

    def close(self):
        """Closes serial connection."""
        self.conn.close()

    def send(self, message, payload=None):
        """Formats message and payload into packet and sends it to device.

        Args:
            message: Command message to send.
            payload: Additional payload to send in packet.
        """
        if message != Message.HEAD_COMMAND:
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
            while True:
                # Read until new line using the readConn's readline method.
                current_line = self.readConn.readline()
                if current_line is None:
                    continue                

                # Try to parse the packet.
                try:
                    reply = Reply(current_line)
                    break
                except PacketIncomplete:
                    # Keep looking for a complete packet.
                    continue

            self.node.get_logger().debug(f"Received {reply.name}: {reply.payload}")
            return reply
        except select.error as code:
            # Handle EINTR as KeyboardInterrupt.
            if code == errno.EINTR:
                raise KeyboardInterrupt()

            # Otherwise, re-raise the exception.
            raise
        except PacketCorrupted as e:
            self.node.get_logger().error(f"Packet corrupted: {e}")
            raise
        except Exception as e:
            self.node.get_logger().error(f"Unexpected error: {e}")
            raise
