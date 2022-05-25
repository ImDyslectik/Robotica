import os
import errno
import string
import sys
sys.path.insert(1,'/home/pi/shared/scripts/Robotica/Facade/P')
import classes
from classes import Motor

#define the path to our pipe
Command = '/tmp/command'
movement = classes.Movement(motor1=classes.Motor(1),motor2=classes.Motor(2))

try:
    #try to make a fifo (pipe), this might throw an error
    os.mkfifo(Command)
except OSError as oe: 
    if oe.errno != errno.EEXIST:
        #if there is an error from the os, say this
        print("error")
        raise

"""----------------------------------------------------------------------------------------------------
open the pipe in read only mode first to read the commands written by Vision 
put all the commands into a variable @param direction
then we open the file in write only mode erasing all content so far written
write the commands gathered into the file which will be used in readFirst.c
"""----------------------------------------------------------------------------------------------------

print("Opening File...")
with open(Command,"r") as fifo:
    print("Command File opened")
    direction = fifo.read()
    with open(Command,"w") as fifo:
        for c in direction:
            fifo.write(direction + "\n")