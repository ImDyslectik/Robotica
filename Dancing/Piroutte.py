import time
import classes

#TODO really need to move above import into a different folder but python is annoying
movement = classes.Movement(motor1=classes.Motor(1),motor2=classes.Motor(2),motor3=classes.Motor(3),motor4=classes.Motor(4))

start_time = time.time()
seconds = 4

while True:
    current_time = time.time()
    elapsed_time = current_time - start_time
    while(elapsed_time < 4):
        movement.Left()
        break

    if elapsed_time > seconds:
        print("motor on for: " + str(int(elapsed_time))  + " seconds, change this to preffered time for maximum spinnange")
        break