def nearly_equal(a, b):
    if a == b:
        return True
    if abs(len(a) - len(b)) > 1:
        return False

    count = 0
    i = j = 0
    while i < len(a) and j < len(b):
        if a[i] != b[j]:
            count += 1
            if count > 1:
                return False
            if len(a) > len(b):
                i += 1
                continue
            elif len(b) > len(a):
                j += 1
                continue
        i += 1
        j += 1
    return True

print(nearly_equal(input(), input()))
