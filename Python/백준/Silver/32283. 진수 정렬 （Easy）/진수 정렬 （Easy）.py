from itertools import product

N = int(input())
S = input()

all_binary = ["".join(bits) for bits in product("01", repeat=N)]
all_binary.sort(key=lambda x: (x.count('1'), int(x[::-1], 2)))

print(all_binary.index(S))
