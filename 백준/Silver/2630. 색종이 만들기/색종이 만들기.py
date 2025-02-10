import sys

def count_paper(x, y, size):
    global white, blue
    color = paper[x][y]
    
    for i in range(x, x + size):
        for j in range(y, y + size):
            if paper[i][j] != color:
                new_size = size // 2
                count_paper(x, y, new_size)
                count_paper(x, y + new_size, new_size)
                count_paper(x + new_size, y, new_size)
                count_paper(x + new_size, y + new_size, new_size)
                return
    
    if color == 0:
        white += 1
    else:
        blue += 1

sys.setrecursionlimit(10**6)
n = int(sys.stdin.readline().strip())
paper = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

white, blue = 0, 0
count_paper(0, 0, n)

print(white)
print(blue)
