import sys

def merge_sorted_arrays():

    input = sys.stdin.read
    data = input().split()

    N, M = int(data[0]), int(data[1])
    A = list(map(int, data[2:2 + N]))
    B = list(map(int, data[2 + N:]))

    result = []
    i, j = 0, 0

    while i < N and j < M:
        if A[i] <= B[j]:
            result.append(A[i])
            i += 1
        else:
            result.append(B[j])
            j += 1

    if i < N:
        result.extend(A[i:])
    if j < M:
        result.extend(B[j:])

    print(" ".join(map(str, result)))

merge_sorted_arrays()
