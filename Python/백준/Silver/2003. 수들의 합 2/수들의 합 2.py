def count_subarrays_with_sum(N, M, A):
    left, right = 0, 0
    current_sum = 0
    count = 0

    while right < N:
        current_sum += A[right]

        while current_sum > M and left <= right:
            current_sum -= A[left]
            left += 1

        if current_sum == M:
            count += 1

        right += 1

    return count

N, M = map(int, input().split())
A = list(map(int, input().split()))

result = count_subarrays_with_sum(N, M, A)
print(result)