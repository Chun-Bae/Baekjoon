from collections import deque
import sys

def build_game(N, build_info):
    graph = [[] for _ in range(N+1)]
    in_degree = [0] * (N+1)
    build_time = [0] * (N+1)
    result = [0] * (N+1) 

    for i in range(1, N+1):
        data = build_info[i-1]
        build_time[i] = data[0] 
        for pre in data[1:-1]:  
            graph[pre].append(i) 
            in_degree[i] += 1  

    queue = deque()
    for i in range(1, N+1):
        if in_degree[i] == 0: 
            queue.append(i)
            result[i] = build_time[i]

    while queue:
        current = queue.popleft()

        for next_building in graph[current]:
            in_degree[next_building] -= 1  
            result[next_building] = max(result[next_building], result[current] + build_time[next_building])
            
            if in_degree[next_building] == 0:
                queue.append(next_building)

    return result[1:]  

N = int(sys.stdin.readline().strip())
build_info = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

for time in build_game(N, build_info):
    print(time)