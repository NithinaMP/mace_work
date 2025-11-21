s = input("Enter string: ")

if len(s) > 7 and len(s) % 2 == 1:
    mid = len(s) // 2
    new = s[mid-1 : mid+2]
    print("New string:", new)
else:
    print("String length must be > 7 and odd")
