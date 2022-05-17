import os
import errno
import string
from tkinter import W
from Vision.classes import Movement
import classes
#define the path to our pipe
FIFO = '/tmp/myfifo'
movement = classes.Movement(motor1=classes.Motor(1),motor2=classes.Motor(2),motor3=classes.Motor(3),motor4=classes.Motor(4))



try:
    #try to make a fifo (pipe), this might throw an error
    os.mkfifo(FIFO)
except OSError as oe: 
    if oe.errno != errno.EEXIST:
        #if there is an error from the os, say this
        raise

print("Opening FIFO...")
#open the pipe
with open(FIFO) as fifo:
    print("FIFO opened")
    while True:
        #read data from the pipe
        fifo.open("data","w+")
        fifo.write(Movement.Left)
        fifo.close()
        data = fifo.write(string)
        #read until the writer is empty
        if len(data) == 0:
            print("Writer closed")
            break
        #print what we read!
        print('Read: {0}'.format(data))