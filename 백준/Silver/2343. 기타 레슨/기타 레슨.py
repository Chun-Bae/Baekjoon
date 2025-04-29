def count_blurays(lectures, capacity):
    count = 1
    total = 0
    for lecture in lectures:
        if total + lecture > capacity:
            count += 1
            total = lecture
        else:
            total += lecture
    return count

def minimum_bluray_size(n, m, lectures):
    left = max(lectures) 
    right = sum(lectures)

    result = right

    while left <= right:
        mid = (left + right) // 2
        required = count_blurays(lectures, mid)

        if required <= m:
            result = mid
            right = mid - 1
        else:
            left = mid + 1

    return result

n, m = map(int, input().split())
lectures = list(map(int, input().split()))
print(minimum_bluray_size(n, m, lectures))