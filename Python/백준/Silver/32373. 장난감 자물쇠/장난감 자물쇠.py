import sys

N, k = map(int, sys.stdin.readline().split())
A = list(map(int, sys.stdin.readline().split()))
N = len(A)

groups = [[] for _ in range(k)]
desired = [[] for _ in range(k)]
possible = True

for i in range(N):
    c = i % k
    groups[c].append(A[i])
    desired[c].append(i)
    
for c in range(k):
    if sorted(groups[c]) != sorted(desired[c]):
        possible = False
        break
    
if possible:
    print('Yes')
else:
    print('No')
