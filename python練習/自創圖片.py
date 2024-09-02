import cv2
import numpy as np #命名為np
import random

abc=np.empty((300,300,3),np.uint8)  #8個bit   正整數

for row in range(300):
    for col in range(300):
        abc[row][col]=[random.randint(0,255),random.randint(0,255),random.randint(0,255)]#隨機生成
         #  B G R
cv2.imshow('abc',abc)
cv2.waitKey(0)