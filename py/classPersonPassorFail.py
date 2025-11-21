class Person:
    def __init__(self, name, roll):
        self.name = name
        self.roll = roll

class Marks:
    def __init__(self, maths, comp):
        self.maths = maths
        self.comp = comp

class Student(Person, Marks):
    def __init__(self, name, roll, maths, comp):
        Person.__init__(self, name, roll)
        Marks.__init__(self, maths, comp)

    def display(self):
        total = (self.maths + self.comp)/2
        print("Name:", self.name)
        print("Roll:", self.roll)
        print("Maths:", self.maths)
        print("Computer:", self.comp)
        print("Result:", "Pass" if total >= 50 else "Fail")

s1 = Student("Anu", 1, 60, 70)
s1.display()
