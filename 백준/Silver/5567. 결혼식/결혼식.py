from collections import deque

def count_invitees(n, m, friendships):
    graph = {i: [] for i in range(1, n+1)}
    
    for a, b in friendships:
        graph[a].append(b)
        graph[b].append(a)
    
    visited = set()
    queue = deque([(1, 0)]) 
    invited = set()
    
    while queue:
        node, depth = queue.popleft()
        
        if node in visited:
            continue
        visited.add(node)
        
        if 1 <= depth <= 2:
            invited.add(node)
        
        if depth < 2:  
            for friend in graph[node]:
                if friend not in visited:
                    queue.append((friend, depth + 1))
    
    return len(invited)

n = int(input())
m = int(input())
friendships = [tuple(map(int, input().split())) for _ in range(m)]

print(count_invitees(n, m, friendships))