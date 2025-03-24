def nth_sum_of_distinct_powers_of_3(N):
    result = 0
    power = 0
    while N > 0:
        if N & 1:
            result += 3 ** power
        N >>= 1
        power += 1
    return result

N = int(input())
print(nth_sum_of_distinct_powers_of_3(N))