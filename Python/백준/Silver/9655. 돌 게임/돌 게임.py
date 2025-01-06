def dol_game(n):
    dp = [0] * (n + 1)

    dp[1] = 1 
    if n > 1:
        dp[2] = 0
    if n > 2:
        dp[3] = 1

    for i in range(4, n + 1):
        if dp[i - 1] == 0 or dp[i - 3] == 0:
            dp[i] = 1
        else:
            dp[i] = 0

    return "SK" if dp[n] == 1 else "CY"


n = int(input())
print(dol_game(n))
