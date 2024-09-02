import cv2
abc=cv2.VideoCapture('123.mp4')

while True:

    ret, fame =abc.read()
    if ret:
   
      cv2.imshow('aaa',fame) 
    else:
       break
    if cv2.waitKey(100)== ord('q'):
       break 
