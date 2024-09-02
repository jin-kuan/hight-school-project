result={"david":0,"any":0,"sean":0}
for i in range(3):
    vote=input("投票")
    if vote not in result:
        print("無效票")
        continue
    result[vote]+=1
print(result)