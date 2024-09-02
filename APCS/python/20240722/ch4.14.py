class Employee:
    def __init__(self,name,salary):
        self.name=name
        self.salary=salary
    def printInfo(self):
        print("name:",self.name,"salary:",self.salary)



        
emp=Employee("vivin",35000)
print(emp.name)
print(emp.salary)
emp.printInfo()
