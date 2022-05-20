import os
import errno
import string

import sys
sys.path.insert(1,'/home/pi/shared/scripts/Robotica/Facade/P')
import classes
from classes import Motor

#define the path to our pipe
FIFO = '/tmp/myfifo'
Vision = '/tmp/command'
movement = classes.Movement(motor1=classes.Motor(1),motor2=classes.Motor(2))

try:
    #try to make a fifo (pipe), this might throw an error
    os.mkfifo(FIFO)
except OSError as oe: 
    if oe.errno != errno.EEXIST:
        #if there is an error from the os, say this
        raise

print("Opening FIFO...")
#open the pipe
with open(Vision,"r") as fifo:
    print("FIFO opened")
    direction =  fifo.read()
    fifo.close()
    with open(Vision,"w") as fifo:
        for c in direction:
            fifo.write(c + "\n")
    # while True:
    #     #write data to the pipe
    #     data = fifo.write("")
    #     if len(data) == 0:
    #         print("Writer closed")
    #         break
    #     #print what we read!
    #     print('Read: {0}'.format(data))
