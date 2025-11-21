items=input("Enter elements(space seperated):").split()
total=0
for x in items:
    if x.isdigit():
        total+=int(x)
print("Sum of numbers:",total)
