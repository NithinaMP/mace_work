class Engine:
    def __init__(self, power):
        self.power = power

    def display(self):
        print("Engine Power:", self.power, "HP")


class Wheels:
    def __init__(self, size):
        self.size = size

    def display(self):
        print("Wheel Size:", self.size, "inch")


class Car(Engine, Wheels):
    def __init__(self, power, size, model):
        Engine.__init__(self, power)
        Wheels.__init__(self, size)
        self.model = model

    def display(self):
        print("Car Model:", self.model)
        Engine.display(self)
        Wheels.display(self)


# Main program
c = Car(150, 16, "Hyundai i20")
c.display()
