def find_closest_to_zero(N, A):
    left, right = 0, N - 1
    closest_sum = float('inf')
    result = (0, 0)

    while left < right:
        current_sum = A[left] + A[right]

        if abs(current_sum) < abs(closest_sum):
            closest_sum = current_sum
            result = (A[left], A[right])

        if current_sum < 0:
            left += 1
        elif current_sum > 0:
            right -= 1
        else: 
            break

    return closest_sum

N = int(input())
A = list(map(int, input().split()))

print(find_closest_to_zero(N, A))
