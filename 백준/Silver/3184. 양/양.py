import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.read

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def dfs(x, y):
    global sheep, wolves
    stack = [(x, y)]
    visited[x][y] = True
    local_sheep, local_wolves = 0, 0

    while stack:
        cx, cy = stack.pop()

        # 현재 위치가 양이면 개수 증가
        if yard[cx][cy] == 'o':
            local_sheep += 1
        elif yard[cx][cy] == 'v':
            local_wolves += 1

        # 상하좌우 탐색
        for d in range(4):
            nx, ny = cx + dx[d], cy + dy[d]

            if 0 <= nx < R and 0 <= ny < C and not visited[nx][ny] and yard[nx][ny] != '#':
                visited[nx][ny] = True
                stack.append((nx, ny))

    if local_sheep > local_wolves:
        sheep += local_sheep
    else:
        wolves += local_wolves

data = input().splitlines()
R, C = map(int, data[0].split())
yard = [list(data[i+1]) for i in range(R)]
visited = [[False] * C for _ in range(R)]

sheep, wolves = 0, 0 

for i in range(R):
    for j in range(C):
        if yard[i][j] != '#' and not visited[i][j]:  # 울타리가 아니면서 방문 안 한 경우
            dfs(i, j)

print(sheep, wolves)