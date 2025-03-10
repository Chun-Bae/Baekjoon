import sys
from itertools import product

def solve():
    n, m = map(int, sys.stdin.readline().split())
    numbers = sorted(set(map(int, sys.stdin.readline().split())))  # 중복 제거 후 정렬
    
    for seq in product(numbers, repeat=m):
        print(*seq)

if __name__ == "__main__":
    solve()