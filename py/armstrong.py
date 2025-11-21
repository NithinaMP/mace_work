for n in range(100, 500):
    s = 0
    temp = n
    while temp > 0:
        d = temp % 10
        s += d ** 3
        temp //= 10
    if s == n:
        print(n)
