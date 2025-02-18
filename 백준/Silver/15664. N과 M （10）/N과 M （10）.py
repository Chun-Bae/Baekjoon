import sys
from itertools import combinations

def solve():
    n, m = map(int, sys.stdin.readline().split())
    numbers = sorted(map(int, sys.stdin.readline().split()))
    
    unique_combinations = sorted(set(combinations(numbers, m)))
    
    for combo in unique_combinations:
        print(*combo)

if __name__ == "__main__":
    solve()
