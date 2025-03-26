from collections import deque

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

def label_island(x, y, island_id):
    queue = deque()
    queue.append((x, y))
    board[x][y] = island_id
    while queue:
        x, y = queue.popleft()
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < N and 0 <= ny < N and board[nx][ny] == 1:
                board[nx][ny] = island_id
                queue.append((nx, ny))

def bfs():
    dist = [[-1] * N for _ in range(N)]
    queue = deque()

    for i in range(N):
        for j in range(N):
            if board[i][j] > 0:
                dist[i][j] = 0
                queue.append((i, j))

    min_dist = float('inf')

    while queue:
        x, y = queue.popleft()
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < N and 0 <= ny < N:
                if board[nx][ny] == 0 and dist[nx][ny] == -1:
                    dist[nx][ny] = dist[x][y] + 1
                    board[nx][ny] = board[x][y] 
                    queue.append((nx, ny))
                elif board[nx][ny] > 0 and board[nx][ny] != board[x][y]:
                    min_dist = min(min_dist, dist[x][y] + dist[nx][ny])

    return min_dist

N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]

island_id = 2
for i in range(N):
    for j in range(N):
        if board[i][j] == 1:
            label_island(i, j, island_id)
            island_id += 1

print(bfs())