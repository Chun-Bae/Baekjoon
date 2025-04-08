from collections import deque

def escape_forest(R, C, forest):
    water_q = deque()
    hedgehog_q = deque()
    visited = [[False] * C for _ in range(R)]
    
    for i in range(R):
        for j in range(C):
            if forest[i][j] == 'S':
                hedgehog_q.append((i, j, 0)) 
                visited[i][j] = True
            elif forest[i][j] == '*':
                water_q.append((i, j))

    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]

    while hedgehog_q:
        for _ in range(len(water_q)):
            x, y = water_q.popleft()
            for dir in range(4):
                nx, ny = x + dx[dir], y + dy[dir]
                if 0 <= nx < R and 0 <= ny < C:
                    if forest[nx][ny] == '.':
                        forest[nx][ny] = '*'
                        water_q.append((nx, ny))
        
        for _ in range(len(hedgehog_q)):
            x, y, time = hedgehog_q.popleft()
            for dir in range(4):
                nx, ny = x + dx[dir], y + dy[dir]
                if 0 <= nx < R and 0 <= ny < C:
                    if forest[nx][ny] == 'D':
                        return time + 1
                    if forest[nx][ny] == '.' and not visited[nx][ny]:
                        visited[nx][ny] = True
                        hedgehog_q.append((nx, ny, time + 1))

    return "KAKTUS"

R, C = map(int, input().split())
forest = [list(input().strip()) for _ in range(R)]
print(escape_forest(R, C, forest))