from collections import Counter
import sys


def longest_common_permutation(a, b):
    count_a = Counter(a)
    count_b = Counter(b)

    common_chars = []
    for char in count_a:
        if char in count_b:
            common_chars.append((char, min(count_a[char], count_b[char]))) 

    common_chars.sort()

    result = "".join(char * freq for char, freq in common_chars)

    return result


input = sys.stdin.read
data = input().strip().split("\n")


for i in range(0, len(data), 2):
    if i + 1 < len(data):
        a = data[i].strip()
        b = data[i + 1].strip()
        print(longest_common_permutation(a, b))
