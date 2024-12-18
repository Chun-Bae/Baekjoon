def max_weight():
    import sys
    input = sys.stdin.read

    data = input().split()
    N = int(data[0])
    ropes = list(map(int, data[1:]))

    ropes.sort(reverse=True)

    max_weight = 0
    for i in range(N):
        weight = ropes[i] * (i + 1)
        max_weight = max(max_weight, weight)

    print(max_weight)

max_weight()