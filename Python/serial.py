import serial
# https://pyserial.readthedocs.io/en/latest/

def read_Serial(serial_device):
    # gets data from serial port
    line_read = serial_device.readline()
    return line_read

if (__name__) == "__main__":
    # Must define serial port here, currently it is COM3
    serial_device = serial.Serial(port='COM3')
    while(1):
        if serial_device.in_waiting:
            print(read_serial())
