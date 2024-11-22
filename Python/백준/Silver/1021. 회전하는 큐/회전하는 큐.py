from collections import deque

N, M = map(int, input().split())
positions = list(map(int, input().split()))
queue = deque(range(1, N+1))
count = 0

for pos in positions:
    idx = queue.index(pos)
    
    if idx <= len(queue) // 2:
        queue.rotate(-idx)
        count += idx
    else:
        queue.rotate(len(queue) - idx)
        count += len(queue) - idx
    
    queue.popleft()

print(count)
