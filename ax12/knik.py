import serial
import time
import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)
GPIO.setup(18, GPIO.OUT)

port = serial.Serial("/dev/ttyAMA0", baudrate=1000000, timeout=3.0)
print("dit programma is")

for x in range(3):
        GPIO.output(18, GPIO.HIGH)
        port.write(bytearray.fromhex("FF FF 12 05 03 20 FF 07 BF"))
        time.sleep(0.0000001)
        GPIO.output(18, GPIO.LOW)
        while port.in_waiting:
            print(port.read())
        print("Boven_Motor_21")

        time.sleep(3)
        GPIO.output(18, GPIO.HIGH)
        port.write(bytearray.fromhex("FF FF 12 05 03 20 00 00 C5"))
        time.sleep(0.0000001)
        GPIO.output(18, GPIO.LOW)
        while port.in_waiting:
            print(port.read())
        print("Boven_Motor_21")

        time.sleep(1)

        print(x)

GPIO.cleanup()
