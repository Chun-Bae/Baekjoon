from collections import defaultdict, deque
import sys

def is_bipartite(graph, n):
    colors = [-1] * (n + 1)

    for start in range(1, n + 1):
        if colors[start] == -1: 
            queue = deque([start])
            colors[start] = 0  

            while queue:
                current = queue.popleft()
                current_color = colors[current]

                for neighbor in graph[current]:
                    if colors[neighbor] == -1: 
                        colors[neighbor] = 1 - current_color
                        queue.append(neighbor)
                    elif colors[neighbor] == current_color: 
                        return 0

    return 1

input = sys.stdin.read
data = input().splitlines()

n, m = map(int, data[0].split())
graph = defaultdict(list)

for i in range(1, m + 1):
    a, b = map(int, data[i].split())
    graph[a].append(b)
    graph[b].append(a)

result = is_bipartite(graph, n)
print(result)

