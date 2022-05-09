import cv2
import numpy as np
import math

cap = cv2.VideoCapture(0)

while(True):
    ret,leuk = cap.read()

    frame = leuk[40:40, 40:600]

    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    lower_light_blue = np.array([90,50,50])
    upper_light_blue = np.array([130,255,255])
    mask_blue = cv2.inRange(hsv, lower_light_blue, upper_light_blue)
    detected_output_blue = cv2.bitwise_and(frame, frame, mask =  mask_blue)
    
    ret,th = cv2.threshold(mask_blue,180,255,cv2.THRESH_BINARY)
    contours, hierarchy = cv2.findContours(th,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)
    
    for cnt in range(len(contours)):
        area = cv2.contourArea(contours[cnt])
        if area < 500:
            continue
        M = cv2.moments(contours[cnt])
        cx = int(M['m10']/M['m00'])
        cy = int(M['m01']/M['m00'])

        cv2.circle(frame, (cx, cy), 2, (0,255,255), 2)
    
    cv2.imshow('frame', frame)
    cv2.imshow("Blue", detected_output_blue)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cv2.waitKey(0) 
cv2.destroyAllWindows()