from collections import deque, defaultdict

N, M, K = map(int, input().split())
fireballs = deque()

for _ in range(M):
    r, c, m, s, d = map(int, input().split())
    fireballs.append((r-1, c-1, m, s, d)) 

directions = [(-1,0), (-1,1), (0,1), (1,1), (1,0), (1,-1), (0,-1), (-1,-1)]

for _ in range(K):
    grid = defaultdict(list)

    while fireballs:
        r, c, m, s, d = fireballs.popleft()
        dr, dc = directions[d]
        nr = (r + dr * s) % N
        nc = (c + dc * s) % N
        grid[(nr, nc)].append((m, s, d))

    for (r, c), balls in grid.items():
        if len(balls) == 1:
            fireballs.append((r, c, *balls[0]))
        else:
            total_m = sum(b[0] for b in balls)
            total_s = sum(b[1] for b in balls)
            count = len(balls)
            new_m = total_m // 5
            if new_m == 0:
                continue
            new_s = total_s // count
            dirs = [b[2] % 2 for b in balls]
            if all(d == dirs[0] for d in dirs): 
                new_dirs = [0, 2, 4, 6]
            else:
                new_dirs = [1, 3, 5, 7]
            for nd in new_dirs:
                fireballs.append((r, c, new_m, new_s, nd))

print(sum(f[2] for f in fireballs))