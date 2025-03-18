import sys

# (←, ↖, ↑, ↗, →, ↘, ↓, ↙)
dx = [0, -1, -1, -1, 0, 1, 1, 1]
dy = [-1, -1, 0, 1, 1, 1, 0, -1]

def move_clouds(clouds, direction, distance, N):
    new_clouds = set()
    for x, y in clouds:
        nx = (x + dx[direction] * distance) % N
        ny = (y + dy[direction] * distance) % N
        new_clouds.add((nx, ny))
    return new_clouds

def rain_and_water_copy_bug(grid, clouds, N):
    for x, y in clouds:
        grid[x][y] += 1
    
    for x, y in clouds:
        count = 0
        for i in [1, 3, 5, 7]:  # 대각선 방향
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < N and 0 <= ny < N and grid[nx][ny] > 0:
                count += 1
        grid[x][y] += count

def generate_new_clouds(grid, previous_clouds, N):
    new_clouds = set()
    for i in range(N):
        for j in range(N):
            if grid[i][j] >= 2 and (i, j) not in previous_clouds:
                new_clouds.add((i, j))
                grid[i][j] -= 2
    return new_clouds

def simulate(N, M, grid, commands):
    clouds = {(N-1, 0), (N-1, 1), (N-2, 0), (N-2, 1)}
    
    for d, s in commands:
        clouds = move_clouds(clouds, d-1, s, N)
        rain_and_water_copy_bug(grid, clouds, N)
        clouds = generate_new_clouds(grid, clouds, N)
    
    return sum(sum(row) for row in grid)

N, M = map(int, sys.stdin.readline().split())
grid = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
commands = [tuple(map(int, sys.stdin.readline().split())) for _ in range(M)]
print(simulate(N, M, grid, commands))