class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def display(self):
        print("Name:", self.name)
        print("Age:", self.age)


class Employee(Person):
    def __init__(self, name, age, empid):
        super().__init__(name, age)
        self.empid = empid

    def display(self):
        super().display()
        print("Employee ID:", self.empid)


class Faculty(Employee):
    def __init__(self, name, age, empid, department):
        super().__init__(name, age, empid)
        self.department = department

    def display(self):
        super().display()
        print("Department:", self.department)


class Researcher:
    def can_do_research(self):
        return "This person can conduct research."


class Professor(Faculty, Researcher):
    def __init__(self, name, age, empid, department):
        Faculty.__init__(self, name, age, empid, department)

    def display(self):
        super().display()
        print(self.can_do_research())


# Main program
p = Professor("Dr. Smith", 45, "E101", "Computer Science")
p.display()
