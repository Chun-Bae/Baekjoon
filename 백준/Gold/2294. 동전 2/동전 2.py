import sys

def min_coin_count(n, k, coins):
    INF = float('inf')
    dp = [INF] * (k + 1)
    dp[0] = 0  

    for coin in coins:
        for i in range(coin, k + 1):
            dp[i] = min(dp[i], dp[i - coin] + 1)

    return dp[k] if dp[k] != INF else -1  

n, k = map(int, sys.stdin.readline().split())
coins = sorted(set(int(sys.stdin.readline().strip()) for _ in range(n)))

print(min_coin_count(n, k, coins))