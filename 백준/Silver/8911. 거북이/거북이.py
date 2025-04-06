T = int(input()) 

dx = [0, 1, 0, -1] 
dy = [1, 0, -1, 0] 

for _ in range(T):
    commands = input()
    
    x, y = 0, 0  
    dir = 0  
    min_x = max_x = x
    min_y = max_y = y
    
    for cmd in commands:
        if cmd == 'F':
            x += dx[dir]
            y += dy[dir]
        elif cmd == 'B':
            x -= dx[dir]
            y -= dy[dir]
        elif cmd == 'L':
            dir = (dir - 1) % 4
        elif cmd == 'R':
            dir = (dir + 1) % 4

        min_x = min(min_x, x)
        max_x = max(max_x, x)
        min_y = min(min_y, y)
        max_y = max(max_y, y)
    
    width = max_x - min_x
    height = max_y - min_y
    area = width * height
    print(area)