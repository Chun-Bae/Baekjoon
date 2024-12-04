from collections import deque
import sys

def shortest_distance_to_target(n, m, grid):
    target = None
    for i in range(n):
        for j in range(m):
            if grid[i][j] == 2:
                target = (i, j)
                break
        if target:
            break

    distances = [[-1] * m for _ in range(n)]
    distances[target[0]][target[1]] = 0

    queue = deque([target])
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]  # up, down, left, right

    while queue:
        x, y = queue.popleft()
        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            if 0 <= nx < n and 0 <= ny < m and grid[nx][ny] == 1 and distances[nx][ny] == -1:
                distances[nx][ny] = distances[x][y] + 1
                queue.append((nx, ny))

    for i in range(n):
        for j in range(m):
            if grid[i][j] == 0:
                print(0, end=' ')
            else:
                print(distances[i][j], end=' ')
        print()

input = sys.stdin.readline
n, m = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]
shortest_distance_to_target(n, m, grid)
