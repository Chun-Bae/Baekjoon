from itertools import groupby

def find_N(s):
    return max(len(list(group)) for _, group in groupby(s))

s = input().strip()

print(find_N(s))