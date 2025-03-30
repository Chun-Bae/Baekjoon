def solve():
    import sys
    input = sys.stdin.readline
    
    n = int(input().strip())
    board = [list(map(int, input().split())) for _ in range(n)]
    
    visited = [[False] * n for _ in range(n)]
    found = False

    def dfs(x, y):
        nonlocal found
        if found:  
            return
        if board[x][y] == -1:
            found = True
            return
        
        jump = board[x][y]
        if jump == 0:
            return
        
        nx, ny = x, y + jump
        if 0 <= ny < n and not visited[nx][ny]:
            visited[nx][ny] = True
            dfs(nx, ny)
        
        nx, ny = x + jump, y
        if 0 <= nx < n and not visited[nx][ny]:
            visited[nx][ny] = True
            dfs(nx, ny)
    
    visited[0][0] = True
    dfs(0, 0)
    
    print("HaruHaru" if found else "Hing")
    
if __name__ == '__main__':
    solve()