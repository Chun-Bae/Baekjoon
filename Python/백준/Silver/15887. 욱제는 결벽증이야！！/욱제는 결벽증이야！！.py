import sys
input = sys.stdin.read
data = input().split()

N = int(data[0])
cards = list(map(int, data[1:]))

operations = []

for i in range(N):
    if cards[i] != i + 1:
        target_index = cards.index(i + 1)
        cards[i:target_index + 1] = reversed(cards[i:target_index + 1])
        operations.append((i + 1, target_index + 1))

print(len(operations))
for op in sorted(operations):
    print(op[0], op[1])
