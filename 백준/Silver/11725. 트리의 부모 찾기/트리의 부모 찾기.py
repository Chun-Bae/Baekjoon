import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def dfs(node):
    for next_node in tree[node]:
        if parent[next_node] == 0:  
            parent[next_node] = node
            dfs(next_node)

n = int(input().strip())
tree = [[] for _ in range(n + 1)]
parent = [0] * (n + 1)

for _ in range(n - 1):
    a, b = map(int, input().split())
    tree[a].append(b)
    tree[b].append(a)

dfs(1)

for i in range(2, n + 1):
    print(parent[i])