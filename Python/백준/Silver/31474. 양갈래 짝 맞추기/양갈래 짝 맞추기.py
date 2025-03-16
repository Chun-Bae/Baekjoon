import sys

def double_factorial(n):
    if n <= 0:
        return 1
    return n * double_factorial(n - 2)

N = int(sys.stdin.readline().strip())

print(double_factorial(N - 1))
