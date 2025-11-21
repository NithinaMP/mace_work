with open("data.txt","r") as f:
    for line in f:
        line = line.strip()
        if line.startswith("s") and line.endswith("e"):
            print(line)

