def count_consecutive_sums(N):
    count = 0
    start = 1
    end = 1
    current_sum = 1

    while start <= N:
        if current_sum < N:
            end += 1
            current_sum += end
        elif current_sum > N:
            current_sum -= start
            start += 1
        else:
            count += 1
            current_sum -= start
            start += 1

    return count


N = int(input().strip())
print(count_consecutive_sums(N))
