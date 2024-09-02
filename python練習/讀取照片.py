import cv2


abc = cv2.imread('bbbbb.jpg')
img=cv2.resize(abc, (0, 0),fx=0.15,fy=0.15)
cv2.imshow('安妮雅',img)
cv2.waitKey(0)

