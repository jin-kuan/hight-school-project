class Person:
    def __init__(self,name,age):
        self.name=name
        self.age=age
    # def pinrtin(self):
    #     print("name:",self.name,"age:",self.age)
    def __str__(self):
        return f"({self.name},{self.age})"
    def __lt__(self,other):
        return self.age<other.age

def foreachList(personList):
    for v in personList:
        print(v)
    print("=="*30)

p1=Person("lidsn",18)
p2=Person("kiran",20)
p3=Person("fred",34)
p4=Person("rfge",33)
p5=Person("fgrg4g",389)
print(p1.name,p1.age)
print(p1)
print(p3<p4)
print(p5<p1)
personList=[]
personList.append(p1)
personList.append(p2)
personList.append(p3)
personList.append(p4)
personList.append(p5)
foreachList(personList)
newList=sorted(personList)
foreachList(newList)
newList1=sorted(personList,reverse=True)
foreachList(newList1)