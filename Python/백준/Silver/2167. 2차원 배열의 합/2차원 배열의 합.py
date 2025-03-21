import sys

def calculate_prefix_sum(matrix, N, M):
    prefix_sum = [[0] * (M + 1) for _ in range(N + 1)]
    
    for i in range(1, N + 1):
        for j in range(1, M + 1):
            prefix_sum[i][j] = (matrix[i-1][j-1] 
                                + prefix_sum[i-1][j] 
                                + prefix_sum[i][j-1] 
                                - prefix_sum[i-1][j-1])
    return prefix_sum

def sum_subarray(prefix_sum, i, j, x, y):
    return (prefix_sum[x][y] 
            - prefix_sum[i-1][y] 
            - prefix_sum[x][j-1] 
            + prefix_sum[i-1][j-1])


input = sys.stdin.readline

N, M = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(N)]

prefix_sum = calculate_prefix_sum(matrix, N, M)

K = int(input())
for _ in range(K):
    i, j, x, y = map(int, input().split())
    result = sum_subarray(prefix_sum, i, j, x, y)
    print(result)


