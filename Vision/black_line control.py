import numpy as np
import cv2 as cv
import sys
sys.path.insert(1,'/home/pi//shared/scripts/Robotica/Facade/P')
import classes

"""--------------------------------------------------------------------------------------------------
movement: defines actual motors so that it can be used later to sned the direction to our pipe
Command : sets a file path so that we can open it later and write to the file
cap     :creates a videocapture device and with our if not statement, we can check if camera is working
ROI     :here we also reduce width and height for increased performance
---------------------------------------------------------------------------------------------------"""       
movement = classes.Movement(motor1=classes.Motor(1),motor2=classes.Motor(2))
Command = '/tmp/command'
cap = cv.VideoCapture(0)

#check if we can open the camera
if not cap.isOpened():
    print("Cannot open camera")
    exit()
width = cap.get(cv.CAP_PROP_FRAME_WIDTH)
height = cap.get(cv.CAP_PROP_FRAME_HEIGHT)

#define the range of colors we want to filter to
lower = np.array([0,0,0])
upper = np.array([360,255,30])

print("{} {}".format(width, height))
while True:
    ret, frame = cap.read()
    
    #make sure there is a frame to process
    if not ret:
        print("cannot recieve frame")
        break
    
    #set the Region Of Interest for perfomance reasons
    ROI = frame[400:480, 0:640]

    #change the frame to a color format we can use, then filter a mask from our defined range
    hsv = cv.cvtColor(ROI, cv.COLOR_BGR2HSV)

    mask = cv.inRange(hsv, lower, upper)

    res = cv.bitwise_and(ROI,ROI, mask= mask)
    
    ret, thresh = cv.threshold(mask, 127, 255, 0)


    #get contours from the threshholded frame
    contours, hierarchy = cv.findContours(thresh, cv.RETR_TREE, cv.CHAIN_APPROX_SIMPLE)

    if (len(contours) > 0):
        print(len(contours))
        pass
    else:
        with open(Command,"w") as command:
            command.write(movement.Backward())
            print(len(contours))
            pass
            #command.close()


    #for each contour we will check the area to reduce false positives
    for cnt in contours:
        area = cv.contourArea(cnt)
        if area < 500:
            continue

        #calculate the moments of the contours to get the centre of mass
        M = cv.moments(cnt)
        cx = int(M['m10']/M['m00'])
        cy = int(M['m01']/M['m00'])

        cv.circle(ROI, (cx, cy), 2, (0,255,255), 2)

        #make a command depending on where the centre of mass is on the frame
        with open(Command,"w") as command:
            if cx < 270:
                    command.write(movement.Left())
                    #command.close()
                    continue
            if cx > 270 and cx < 370:
                    command.write(movement.Forward())
                    #command.close()
                    continue
            if cx > 370:
                    command.write(movement.Right())
                    #command.close()
                    continue

    #add lines to the frame to show the thresholds for the commands, this should be removed when done debugging
    cv.circle(ROI, (int(width/2), 40), 2, (255,0,255), 2)
    cv.line(ROI, (270, 0), (270, 80), (255,0,255), 2)
    cv.line(ROI, (370, 0), (370, 80), (255,0,255), 2)
    cv.imshow("frame", ROI)
    if cv.waitKey(1) == ord('q'):
        break

#stop capturing the device
cap.release()
cv.destroyAllWindows()