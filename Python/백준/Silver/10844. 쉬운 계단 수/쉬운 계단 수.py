MOD = 1_000_000_000

N = int(input())

dp = [[0] * 10 for _ in range(N + 1)]

for i in range(1, 10):
    dp[1][i] = 1

for length in range(2, N + 1):
    for last_digit in range(10):
        if last_digit > 0:
            dp[length][last_digit] += dp[length - 1][last_digit - 1]
        if last_digit < 9:
            dp[length][last_digit] += dp[length - 1][last_digit + 1]
        dp[length][last_digit] %= MOD

result = sum(dp[N]) % MOD
print(result)