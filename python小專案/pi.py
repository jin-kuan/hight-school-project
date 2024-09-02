import time
from tqdm import tqdm
a=2
b=3

u=time.time()
for x in tqdm(range(1000000000)):
    a+1
    b=b+4/(a*(a+1)*(a+2))-4/((a+2)*(a+3)*(a+4))
    a=a+4
print(b)

end=time.time()
o=end-u
print(o)