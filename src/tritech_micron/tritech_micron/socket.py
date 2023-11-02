#!/usr/bin/env python3

"""Tritech Micron serial communication handler."""

import errno
import serial
import select
import bitstring
from tritech_micron.replies import Reply
from tritech_micron.messages import Message
from tritech_micron.commands import Command
from tritech_micron.exceptions import PacketIncomplete
from tritech_micron.serial_readline import SerialReadline

__author__ = "Anass Al-Wohoush, Jana Pavlasek, Malcolm Watt"


class Socket(object):

    """Serial communication socket.

    Attributes:
        conn: Serial connection.
    """

    def __init__(self, port):
        """Constructs Socket object.

        Args:
            port: Serial port.
        """
        self.conn = serial.Serial(port=port, baudrate=115200)   
        self.readConn = SerialReadline(self.conn)         

    def open(self):
        """Opens serial connection."""
        self.conn.open()            

    def close(self):
        """Closes serial connection."""
        self.conn.close()

    def send(self, message, payload=None):
        """Formats message and payload into packet and sends it to device.

        Args:
            command: Command to send.
            payload: Additional payload to send in packet.
        """

        if message != Message.HEAD_COMMAND:
            cmd = Command(message, payload)        
            self.conn.write(cmd.serialize()) 
        else:
            hex_string = "40303034434c00ff02471380021d8323029999990266666605a3703d06703d0a0928003c000100ff18510854545a007d0019108d005a00e803970340060100000050510908545400005a007d00000000000a"
            self.conn.write(bytearray.fromhex(hex_string))
        
        readHex = " ".join(["{:02x}".format(x) for x in cmd.serialize()])
        print(readHex)  

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
            while not self.conn.read() == bytes("@", 'utf-8'):              
                pass

            # Read one line at a time until packet is complete and parsed.
            packet = bitstring.BitStream("0x40")
            while True:
                # Read until new line.
                current_line = self.readConn.readline()                
                for char in current_line:                    
                    packet.append("0x{:02X}".format(char))

                # Try to parse.
                try:
                    reply = Reply(packet)                    
                    break
                except PacketIncomplete:
                    # Keep looking.
                    continue
            
            return reply
        except select.error as code:
            # Set SIGINT as KeyboardInterrupt correctly, because pyserial has
            # problems.
            if code == errno.EINTR:
                raise KeyboardInterrupt()

            # Otherwise, reraise.
            raise

    