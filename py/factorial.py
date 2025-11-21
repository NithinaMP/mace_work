n = int(input("Enter a non-negative whole number: "))
if n < 0:
    print("Factorial is not defined for negative numbers.")

elif n == 0:
    print(f"The factorial of {n} is: 1")

else:
    result = 1
    for i in range(1, n + 1):
        result *= i
        
    print(f"The factorial of {n} is: {result}")
