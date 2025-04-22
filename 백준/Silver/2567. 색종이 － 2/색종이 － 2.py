paper = [[0] * 100 for _ in range(100)]
n = int(input())

for _ in range(n):
    x, y = map(int, input().split())
    for i in range(x, x + 10):
        for j in range(y, y + 10):
            paper[i][j] = 1

perimeter = 0
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

for i in range(100):
    for j in range(100):
        if paper[i][j] == 1:
            for d in range(4):
                ni = i + dx[d]
                nj = j + dy[d]
                if ni < 0 or ni >= 100 or nj < 0 or nj >= 100 or paper[ni][nj] == 0:
                    perimeter += 1

print(perimeter)