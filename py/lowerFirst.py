s = input("Enter string: ")
lower = ""
upper = ""

for i in s:
    if i.islower():
        lower += i
    else:
        upper += i

print(lower + upper)
