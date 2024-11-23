def binomial_coefficient_mod(n, k, mod=10007):
    C = [[0] * (k + 1) for _ in range(n + 1)]

    for i in range(n + 1):
        for j in range(min(i, k) + 1):
            if j == 0 or j == i:
                C[i][j] = 1
            else:
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod

    return C[n][k]


n, k = map(int, input().split())

print(binomial_coefficient_mod(n, k))
