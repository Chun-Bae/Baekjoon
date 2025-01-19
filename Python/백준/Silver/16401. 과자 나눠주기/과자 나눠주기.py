def max_snack_length(M, N, lengths):
    def can_distribute(mid):
        count = 0
        for length in lengths:
            count += length // mid
        return count >= M

    start, end = 1, max(lengths)
    result = 0

    while start <= end:
        mid = (start + end) // 2
        if can_distribute(mid):
            result = mid  
            start = mid + 1  
        else:
            end = mid - 1  

    return result

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    M, N = int(data[0]), int(data[1])
    lengths = list(map(int, data[2:]))

    print(max_snack_length(M, N, lengths))