import cv2
import numpy as np

abc = cv2.imread('7818cd.png')
abc=cv2.resize(abc, (0, 0),fx=0.25,fy=0.25)
bb=np.ones((10,10),np.uint8)
aa=np.ones((4,4),np.uint8)

abcd=cv2.cvtColor(abc,cv2.COLOR_BGR2GRAY)#換成灰階
abcdef=cv2.GaussianBlur(abc,(11,11),0)#只能用基數(高斯模糊)
abcde=cv2.Canny(abc,180,220)#找邊緣
abcdefg=cv2.dilate(abcde,bb,iterations=1)#膨脹(線條加粗)
abcdefgh=cv2.erode(abcdefg,aa,iterations=4)#侵蝕

cv2.imshow("原圖",abc)#原圖
cv2.imshow('灰階',abcd)#灰階
cv2.imshow('模糊',abcdef)#模糊
cv2.imshow('找邊緣',abcde)#邊緣
cv2.imshow('線條加粗',abcdefg)#膨脹
cv2.imshow('線條變細',abcdefgh)#侵蝕


cv2.waitKey(0)
