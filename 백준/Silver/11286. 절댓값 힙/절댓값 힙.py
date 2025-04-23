import heapq
import sys

input = sys.stdin.read
data = input().split()

n = int(data[0])
commands = list(map(int, data[1:]))

heap = []
result = []

for x in commands:
    if x == 0:
        if heap:
            result.append(heapq.heappop(heap)[1])
        else:
            result.append(0)
    else:
        heapq.heappush(heap, (abs(x), x))

print('\n'.join(map(str, result)))