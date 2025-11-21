import re

pwd = input("Enter password: ")

if (6 <= len(pwd) <= 16 and
    re.search("[a-z]", pwd) and
    re.search("[A-Z]", pwd) and
    re.search("[0-9]", pwd) and
    re.search("[@$#]", pwd)):
    print("Valid password")
else:
    print("Invalid password")
