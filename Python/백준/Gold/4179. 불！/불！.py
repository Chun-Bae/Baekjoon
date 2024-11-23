from collections import deque

R, C = map(int, input().split())
maze = [list(input().strip()) for _ in range(R)]

jihoon = None
fires = []
for i in range(R):
    for j in range(C):
        if maze[i][j] == "J":
            jihoon = (i, j)
        elif maze[i][j] == "F":
            fires.append((i, j))

queue = deque()
fire_time = [[float("inf")] * C for _ in range(R)]
visited = [[False] * C for _ in range(R)]

for fire in fires:
    queue.append((fire[0], fire[1], "F", 0))
    fire_time[fire[0]][fire[1]] = 0

queue.append((jihoon[0], jihoon[1], "J", 0))
visited[jihoon[0]][jihoon[1]] = True

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

while queue:
    x, y, type, time = queue.popleft()

    if type == "J":
        if x == 0 or x == R - 1 or y == 0 or y == C - 1:
            print(time + 1)
            exit()

        if fire_time[x][y] <= time:
            continue

    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]

        if 0 <= nx < R and 0 <= ny < C and maze[nx][ny] != "#":
            if type == "F":
                if fire_time[nx][ny] == float("inf"):
                    fire_time[nx][ny] = time + 1
                    queue.append((nx, ny, "F", time + 1))
            elif type == "J":
                if not visited[nx][ny] and fire_time[nx][ny] > time + 1:
                    visited[nx][ny] = True
                    queue.append((nx, ny, "J", time + 1))

print("IMPOSSIBLE")
