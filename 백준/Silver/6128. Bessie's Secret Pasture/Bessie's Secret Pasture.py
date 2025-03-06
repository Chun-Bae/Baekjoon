def count_ways(N):
    squares = [i*i for i in range(int(N**0.5)+1)]
    two_sums = {}

    for a in squares:
        for b in squares:
            s = a + b
            if s <= N:
                two_sums[s] = two_sums.get(s, 0) + 1

    count = 0
    for c in squares:
        for d in squares:
            s = c + d
            if N - s in two_sums:
                count += two_sums[N - s]

    return count

N = int(input())
print(count_ways(N))