import os
import errno

#define the path to our pipe
FIFO = '/tmp/myfifo'

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
        data = fifo.read()
        #read until the writer is empty
        if len(data) == 0:
            print("Writer closed")
            break
        #print what we read!
        print('Read: {0}'.format(data))