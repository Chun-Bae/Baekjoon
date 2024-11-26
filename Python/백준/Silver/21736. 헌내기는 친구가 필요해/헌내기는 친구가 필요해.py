from collections import deque

def find_doyeon(campus):
    for i in range(len(campus)):
        for j in range(len(campus[0])):
            if campus[i][j] == 'I':
                return i, j
    return -1, -1

def count_friends(N, M, campus):
    dx = [0, 0, 1, -1]  
    dy = [1, -1, 0, 0]
    
    start_x, start_y = find_doyeon(campus)
    visited = [[False] * M for _ in range(N)]
    queue = deque([(start_x, start_y)])
    visited[start_x][start_y] = True
    friends = 0
    
    while queue:
        x, y = queue.popleft()
        
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            
            if 0 <= nx < N and 0 <= ny < M and not visited[nx][ny] and campus[nx][ny] != 'X':
                visited[nx][ny] = True
                queue.append((nx, ny))
                if campus[nx][ny] == 'P':
                    friends += 1
    
    return friends

N, M = map(int, input().split())
campus = [list(input()) for _ in range(N)]

result = count_friends(N, M, campus)
print(result if result > 0 else "TT")
