def longest_decreasing_subsequence(n, sequence):
    dp = [1] * n 

    for i in range(1, n):
        for j in range(i):
            if sequence[j] > sequence[i]:
                dp[i] = max(dp[i], dp[j] + 1)

    return max(dp)

n = int(input())  
sequence = list(map(int, input().split()))  

result = longest_decreasing_subsequence(n, sequence)
print(result)
