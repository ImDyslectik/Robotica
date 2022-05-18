import serial
import time
import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)
GPIO.setup(18, GPIO.OUT)

port = serial.Serial("/dev/ttyAMA0", baudrate=1000000, timeout=3.0)
print("dit programma is")

while True:
        GPIO.output(18, GPIO.HIGH)
        port.write(bytearray.fromhex("FF FF 15 05 03 1E 05 02 BD"))
        time.sleep(0.0000001)
        GPIO.output(18, GPIO.LOW)
        time.sleep(3)
        while port.in_waiting:
            print(port.read())
        print("Boven")
        time.sleep(7)

        GPIO.output(18,GPIO.HIGH)
        port.write(bytearray.fromhex("FF FF 15 05 03 1E CD 00 F7"))
        time.sleep(0.0000001)
        GPIO.output(18,GPIO.LOW)
        time.sleep(3)
        while port.in_waiting:
            print(port.read())
        print("Rechts")
        time.sleep(8)

GPIO.cleanup()
        
