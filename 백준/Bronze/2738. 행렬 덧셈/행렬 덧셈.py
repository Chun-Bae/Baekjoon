n, m = map(int, input().split())

A = [list(map(int, input().split())) for _ in range(n)]
B = [list(map(int, input().split())) for _ in range(n)]

result = []
for i in range(n):
    row = []
    for j in range(m):
        row.append(A[i][j] + B[i][j])
    result.append(row)

for row in result:
    print(' '.join(map(str, row)))