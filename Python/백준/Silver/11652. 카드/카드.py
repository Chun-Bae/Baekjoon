import sys
from collections import Counter

n = int(sys.stdin.readline().strip())
cards = [int(sys.stdin.readline().strip()) for _ in range(n)]
count = Counter(cards)
most_common = sorted(count.items(), key=lambda x: (-x[1], x[0]))

print(most_common[0][0])
