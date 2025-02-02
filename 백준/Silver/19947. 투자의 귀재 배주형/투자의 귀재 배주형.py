def max_investment(H, Y):
    dp = [0] * (Y + 1)
    dp[0] = H  

    for i in range(Y + 1):
        if i + 1 <= Y:
            dp[i + 1] = max(dp[i + 1], int(dp[i] * 1.05))
        if i + 3 <= Y:
            dp[i + 3] = max(dp[i + 3], int(dp[i] * 1.2))
        if i + 5 <= Y:
            dp[i + 5] = max(dp[i + 5], int(dp[i] * 1.35))

    return dp[Y]

H, Y = map(int, input().split())

print(max_investment(H, Y))