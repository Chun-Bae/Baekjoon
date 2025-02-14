import sys

def backtrack(arr, used, result, numbers, n, m):
    if len(arr) == m:
        print(*arr)
        return

    prev = -1 
    for i in range(n):
        if not used[i] and numbers[i] != prev:
            used[i] = True
            arr.append(numbers[i])
            backtrack(arr, used, result, numbers, n, m)
            arr.pop()
            used[i] = False
            prev = numbers[i] 

def solve():
    n, m = map(int, sys.stdin.readline().split())
    numbers = sorted(map(int, sys.stdin.readline().split())) 

    used = [False] * n
    backtrack([], used, set(), numbers, n, m)

if __name__ == "__main__":
    solve()