import serial
import time
import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)
GPIO.setup(18, GPIO.OUT)

port = serial.Serial("/dev/ttyAMA0", baudrate=1000000, timeout=3.0)
print("dit programma is")

while True:
        GPIO.output(18, GPIO.HIGH)
        port.write(bytearray.fromhex("FF FF FE 05 03 1E 32 03 A6"))
        time.sleep(0.0000001)
        GPIO.output(18, GPIO.LOW)
        time.sleep(3)
        while port.in_waiting:
            print(port.read())
        print("EEN FIETS")

        GPIO.output(18,GPIO.HIGH)
        port.write(bytearray.fromhex("FF FF FE 05 03 1E CD 00 0E"))
        time.sleep(0.0000001)
        GPIO.output(18,GPIO.LOW)
        time.sleep(3)
        while port.in_waiting:
            print(port.read())
        print("ZONDER BANDEN")

GPIO.cleanup()
        