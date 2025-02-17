def solve_tn(n):
    t = [0] * (n + 1)
    t[0] = 1

    for i in range(1, n + 1):
        t[i] = sum(t[j] * t[i - 1 - j] for j in range(i))
    
    return t[n]

n = int(input())
print(solve_tn(n))