class Flower:
    def __init__(self, name):
        self.name = name

f = Flower(input("Enter flower name: "))
f.petalColor = input("Enter petal color: ")

if f.petalColor:
    print(f.petalColor, f.name)
else:
    print("Unknown Flower")
