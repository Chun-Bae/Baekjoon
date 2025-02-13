def count_non_decreasing_numbers(n):
    dp = [[0] * 10 for _ in range(n + 1)]

    for j in range(10):
        dp[1][j] = 1

    for i in range(2, n + 1):  
        for j in range(10):
            dp[i][j] = sum(dp[i - 1][k] for k in range(j + 1))

    return sum(dp[n])

T = int(input())
for _ in range(T):
    n = int(input())
    print(count_non_decreasing_numbers(n))