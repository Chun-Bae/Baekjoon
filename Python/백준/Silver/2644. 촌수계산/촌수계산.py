from collections import deque
import sys

def calculate_kinship(n, person1, person2, relationships):
    graph = {i: [] for i in range(1, n + 1)}
    for parent, child in relationships:
        graph[parent].append(child)
        graph[child].append(parent)  

    def bfs(start, end):
        visited = {i: False for i in range(1, n + 1)}
        queue = deque([(start, 0)])
        visited[start] = True

        while queue:
            current, distance = queue.popleft()
            if current == end:
                return distance

            for neighbor in graph[current]:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    queue.append((neighbor, distance + 1))

        return -1 

    return bfs(person1, person2)


input = sys.stdin.read
data = input().splitlines()

n = int(data[0])

person1, person2 = map(int, data[1].split())

m = int(data[2])

relationships = [tuple(map(int, line.split())) for line in data[3:]]

print(calculate_kinship(n, person1, person2, relationships))
