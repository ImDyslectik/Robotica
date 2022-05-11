import cv2
import numpy as np
import classes
#create videocapture device and check if camera is working
cap = cv2.VideoCapture(0)
movement = classes.Movement(motor1=classes.Motor(1),motor2=classes.Motor(2),motor3=classes.Motor(3),motor4=classes.Motor(4))

if not cap.isOpened():
    print("Cannot open camera")
    exit()

while(True):
    ret,vid = cap.read()
    frame = vid[40:400, 40:600]

    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    #create a blue color mask since we are scanning for a blue block
    lower_light_blue = np.array([90,50,50])
    upper_light_blue = np.array([130,255,255])
    mask_blue = cv2.inRange(hsv, lower_light_blue, upper_light_blue)
    detected_output_blue = cv2.bitwise_and(frame, frame, mask =  mask_blue)
    
    #create a treshhold based on our blue mask we just created
    ret,th = cv2.threshold(mask_blue,180,255,cv2.THRESH_BINARY)
    contours, hierarchy = cv2.findContours(th,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)
    
    #draw contours around objects depending on if the area is smaller then 500
    for cnt in range(len(contours)):
        area = cv2.contourArea(contours[cnt])
        if area < 500:
            continue
        M = cv2.moments(contours[cnt])
        cx = int(M['m10']/M['m00'])
        cy = int(M['m01']/M['m00'])

        if cx < 270:
            movement.Left()
            continue
        if cx > 270 and cx < 370:
            movement.Forward()
            continue
        if cx > 370:
            movement.Right()
            continue
    #show a frame with the result containing contours and a frame with our blue mask for debugging
    #also make a break statement if you want to quit 
    cv2.imshow('frame', frame)
    cv2.imshow("Blue", detected_output_blue)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cv2.destroyAllWindows()