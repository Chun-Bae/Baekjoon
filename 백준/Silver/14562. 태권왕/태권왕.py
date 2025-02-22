from collections import deque

def min_kicks(S, T):
    queue = deque([(S, T, 0)]) 
    visited = set()
    
    while queue:
        s, t, count = queue.popleft()
        
        if s == t:
            return count
        
        if (s, t) in visited:
            continue
        visited.add((s, t))

        if s + 1 <= t:
            queue.append((s + 1, t, count + 1))

        if s * 2 <= t + 3:
            queue.append((s * 2, t + 3, count + 1))

C = int(input().strip())
for _ in range(C):
    S, T = map(int, input().split())
    print(min_kicks(S, T))