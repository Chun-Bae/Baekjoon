from collections import Counter
import sys

def find_universities_id(n, k, ids):
    id_counts = Counter(ids)

    for id, count in id_counts.items():
        if count % k != 0:
            return id


input = sys.stdin.read
data = input().split()

n, k = map(int, data[:2])

ids = list(map(int, data[2:]))

result = find_universities_id(n, k, ids)
print(result)