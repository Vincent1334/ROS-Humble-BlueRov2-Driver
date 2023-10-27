#!/usr/bin/env python3
class SerialReadline:
    """
    Wrapper for pyserial object. serial.readline() uses 100% of one CPU Core,
    since it uses polling mode insead of event trigger mechanism.
    When using serial.readline() serial.in_waiting will keep increasing, and
    therefore the input buffer keeps increasing.
    """

    def __init__(self, serial_obj_):
        self.serial_obj = serial_obj_
        self.buf = bytearray()

    def readline(self):        
        # check for linefeed
        # data after linefeed is saved as part of next line
        i = self.buf.find(b"\n")
        if i >= 0:
            result = self.buf[:i+1]
            self.buf = self.buf[i+1:]
            return result
        while True:
            # read at least 1 byte but max the minimum of
            # 2048 bytes and the input buffer
            data = self.serial_obj.read(
                max(1, min(2048, self.serial_obj.in_waiting)))
            # check for linefeed
            # data after linefeed is saved as part of next line
            i = data.find(b"\n")            
            if i >= 0:
                result = self.buf + data[:i+1]
                self.buf[0:] = data[i+1:]                
                return result
            else:
                self.buf.extend(data)
