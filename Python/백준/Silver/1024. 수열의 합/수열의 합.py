def find_sequence(n, l):
    for length in range(l, 101): 
        start = (n - (length * (length - 1)) // 2) / length
        if start < 0:
            continue

        if start.is_integer(): 
            start = int(start)
            return [start + i for i in range(length)]

    return -1

n, l = map(int, input().split())
result = find_sequence(n, l)
if result == -1:
    print(result)
else:
    print(" ".join(map(str, result)))