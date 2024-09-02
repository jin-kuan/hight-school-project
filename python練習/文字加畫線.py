import cv2
import numpy as np

abc=np.zeros((600,600,3),np.uint8)#純黑的一張圖片
cv2.line(abc,(0,0),(600,600),(255,0,0),2)#條線   起始點 終點 顏色 粗細 
cv2.rectangle(abc,(0,0),(400,300),(0,255,0),cv2.FILLED)#方形(粗細可自定)
cv2.circle(abc,(300,300),50,(0,0,255),5) #圓形  圓心 半徑
cv2.putText(abc,"hahaha",(500,400),cv2.FONT_HERSHEY_COMPLEX,1,(100,100,0),1)#文字 內容 位置 字體 大小 顏色 粗細(不能用中文 )


cv2.imshow('abc',abc)
cv2.waitKey(0)
