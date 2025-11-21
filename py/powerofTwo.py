def is_power_of_two(n):
    if n < 0:
        raise Exception("Negative numbers not allowed")
    return n != 0 and (n & (n - 1)) == 0

num = int(input("Enter number: "))
try:
    if is_power_of_two(num):
        print("Power of 2")
    else:
        print("Not power of 2")
except Exception as e:
    print(e)
