import sys

input = sys.stdin.readline
N = int(input())
expected_ranks = [int(input()) for _ in range(N)]
expected_ranks.sort()

total_discontent = 0
for i in range(N):
    actual_rank = i + 1
    total_discontent += abs(expected_ranks[i] - actual_rank)

print(total_discontent)
