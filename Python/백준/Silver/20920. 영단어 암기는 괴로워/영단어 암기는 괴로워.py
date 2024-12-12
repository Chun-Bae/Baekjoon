import sys
from collections import Counter

input = sys.stdin.read
data = input().splitlines()
N, M = map(int, data[0].split())

words = data[1:]
filtered_words = [word for word in words if len(word) >= M]
word_counts = Counter(filtered_words)
sorted_words = sorted(word_counts.keys(), key=lambda x: (-word_counts[x], -len(x), x))

print("\n".join(sorted_words))