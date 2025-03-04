def max_card_purchase(N, prices):
    dp = [0] * (N + 1)
    
    for i in range(1, N + 1):
        for j in range(1, i + 1):  
            dp[i] = max(dp[i], dp[i - j] + prices[j - 1])

    return dp[N]

N = int(input())
prices = list(map(int, input().split()))

print(max_card_purchase(N, prices))