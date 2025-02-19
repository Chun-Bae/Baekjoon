from collections import deque

def make_one(n):
    dp = [0] * (n + 1)  
    parent = [0] * (n + 1)  
    
    queue = deque([n])
    while queue:
        x = queue.popleft()
        
        if x == 1:
            break
        
        for next_x in (x // 3 if x % 3 == 0 else 0, x // 2 if x % 2 == 0 else 0, x - 1):
            if next_x > 0 and (dp[next_x] == 0 or dp[next_x] > dp[x] + 1):
                dp[next_x] = dp[x] + 1
                parent[next_x] = x
                queue.append(next_x)
    
    print(dp[1])
    
    path = []
    cur = 1
    while cur:
        path.append(cur)
        cur = parent[cur]
    print(" ".join(map(str, reversed(path))))

n = int(input())
make_one(n)
