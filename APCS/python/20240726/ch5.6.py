import random
nums=random.sample(range(1, 50), 6)

spnum=random.randint(1,49)
while(spnum in nums):
    spnum=random.randint(1,49)

print("號碼",sorted(nums))
print("特別",spnum)