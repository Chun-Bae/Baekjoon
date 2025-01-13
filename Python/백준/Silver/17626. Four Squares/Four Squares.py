import math

def is_square(n):
    sqrt_n = int(math.sqrt(n))
    return sqrt_n * sqrt_n == n

def min_square_sum(n):
    if is_square(n):
        return 1
    while n % 4 == 0:
        n //= 4
    if n % 8 == 7:
        return 4

    for i in range(1, int(math.sqrt(n)) + 1):
        if is_square(n - i * i):
            return 2

    return 3

n = int(input())

print(min_square_sum(n))