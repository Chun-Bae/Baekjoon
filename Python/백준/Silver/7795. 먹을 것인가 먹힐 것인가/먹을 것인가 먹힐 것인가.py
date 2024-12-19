from bisect import bisect_left
import sys

def count_pairs(a, b):
    b.sort()
    count = 0

    for value in a:
        count += bisect_left(b, value)

    return count

input = sys.stdin.read
data = input().splitlines()

t = int(data[0]) 
results = []

idx = 1
for _ in range(t):
    n, m = map(int, data[idx].split())
    idx += 1
    a = list(map(int, data[idx].split()))
    idx += 1
    b = list(map(int, data[idx].split())) 
    idx += 1

    results.append(count_pairs(a, b))

for res in results:
    print(res)

