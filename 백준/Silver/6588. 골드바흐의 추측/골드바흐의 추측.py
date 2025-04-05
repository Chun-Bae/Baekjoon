import sys

MAX = 1000000
is_prime = [False, False] + [True] * (MAX - 1)
for i in range(2, int(MAX ** 0.5) + 1):
    if is_prime[i]:
        for j in range(i * i, MAX + 1, i):
            is_prime[j] = False

primes = [i for i in range(3, MAX + 1, 2) if is_prime[i]]

input = sys.stdin.read
nums = list(map(int, input().split()))

for n in nums:
    if n == 0:
        break
    found = False
    for p in primes:
        if p > n // 2:
            break
        if is_prime[n - p]:
            print(f"{n} = {p} + {n - p}")
            found = True
            break
    if not found:
        print("Goldbach's conjecture is wrong.")