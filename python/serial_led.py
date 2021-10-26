import serial
from time import sleep


def get_connection():
    ser = serial.Serial('/dev/cu.usbserial-1420', timeout=1)
    return ser

def running_leds(ser, color):
    while True:
        for i in range(15):
            c = [bytearray([0, 0, 0]) for c in range(15)]
            c[i] = color

            for i in c:
                ser.write(i)
            c.clear()
            sleep(0.1)

        for i in range(13, 0, -1):
            c = [bytearray([0, 0, 0]) for c in range(15)]
            c[i] = color

            for i in c:
                ser.write(i)
            c.clear()
            sleep(0.1)


ser = get_connection()

running_leds(ser, bytearray([255, 255, 0]))