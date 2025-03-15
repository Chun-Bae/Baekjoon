import sys
import math
from itertools import combinations

def gcd_sum(numbers):
    return sum(math.gcd(a, b) for a, b in combinations(numbers, 2))

def main():
    t = int(sys.stdin.readline().strip()) 
    for _ in range(t):
        data = list(map(int, sys.stdin.readline().split()))
        n, numbers = data[0], data[1:]
        print(gcd_sum(numbers))

if __name__ == "__main__":
    main()