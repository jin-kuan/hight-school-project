import cv2
abc=cv2.VideoCapture(0)

while True:

    ret, fame =abc.read()   
    if ret:
     
      cv2.imshow('aaa',fame) 
    else:
       break
    if cv2.waitKey(1 )== ord(' '):
       break 
print(abc) 
