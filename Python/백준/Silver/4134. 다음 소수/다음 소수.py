import math

def is_prime(num):
    if num < 2:
        return False
    if num in (2, 3):
        return True
    if num % 2 == 0 or num % 3 == 0:
        return False
    limit = int(math.sqrt(num)) + 1
    for i in range(5, limit, 6):
        if num % i == 0 or num % (i + 2) == 0:
            return False
    return True

def find_next_prime(n):
    while not is_prime(n):
        n += 1
    return n

t = int(input()) 
results = []
for _ in range(t):
    n = int(input())
    results.append(find_next_prime(n))

print("\n".join(map(str, results)))