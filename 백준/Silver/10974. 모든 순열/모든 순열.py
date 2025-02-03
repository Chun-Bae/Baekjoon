def backtrack(n, perm, visited):
    if len(perm) == n:
        print(" ".join(map(str, perm)))
        return
    
    for i in range(1, n + 1):
        if not visited[i]:
            visited[i] = True
            perm.append(i)
            backtrack(n, perm, visited)
            perm.pop()
            visited[i] = False

n = int(input().strip())
visited = [False] * (n + 1)
backtrack(n, [], visited)