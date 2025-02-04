def find_cycle_count(n, perm):
    visited = [False] * (n + 1)  
    cycle_count = 0 
    
    def dfs(node):
        while not visited[node]:  
            visited[node] = True
            node = perm[node] 

    for i in range(1, n + 1):
        if not visited[i]: 
            dfs(i)
            cycle_count += 1

    return cycle_count

t = int(input()) 
results = []

for _ in range(t):
    n = int(input()) 
    perm = list(map(int, input().split()))
    
    perm.insert(0, 0)  
    results.append(find_cycle_count(n, perm))

for res in results:
    print(res)
