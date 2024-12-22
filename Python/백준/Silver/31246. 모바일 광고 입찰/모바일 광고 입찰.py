import sys

def min_x_to_win(N, K, bids):
    def can_win_with_x(x):
        wins = sum(1 for a, b in bids if a + x >= b)
        return wins >= K

    left, right = 0, 10**9
    result = right

    while left <= right:
        mid = (left + right) // 2
        if can_win_with_x(mid):
            result = mid
            right = mid - 1
        else:
            left = mid + 1

    return result

input = sys.stdin.read
data = input().splitlines()

N, K = map(int, data[0].split())
bids = [tuple(map(int, line.split())) for line in data[1:]]

print(min_x_to_win(N, K, bids))
