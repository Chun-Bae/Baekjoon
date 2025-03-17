import sys

MOD = 1_000_000_009

MAX_N = 1_000_000
dp = [0] * (MAX_N + 1)
dp[1], dp[2], dp[3] = 1, 2, 4

for i in range(4, MAX_N + 1):
    dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD

T = int(sys.stdin.readline().strip())
for _ in range(T):
    n = int(sys.stdin.readline().strip())
    print(dp[n])
