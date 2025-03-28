import sys
input = sys.stdin.read

def longest_even_subarray_after_deletion():
    data = input().split()
    N, K = int(data[0]), int(data[1])
    S = list(map(int, data[2:]))

    start = 0
    max_len = 0
    odd_count = 0

    for end in range(N):
        if S[end] % 2 == 1: 
            odd_count += 1

        while odd_count > K:
            if S[start] % 2 == 1:
                odd_count -= 1
            start += 1
        
        max_len = max(max_len, end - start + 1 - odd_count)

    print(max_len)

longest_even_subarray_after_deletion()