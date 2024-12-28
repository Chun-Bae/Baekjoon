def is_possible(height, n, lamps):
    current_position = 0
    
    for lamp in lamps:
        if lamp - height > current_position:
            return False
        current_position = lamp + height
        if current_position >= n:
            return True

    return current_position >= n

def find_min_height(n, m, lamps):
    left, right = 1, n 
    result = n

    while left <= right:
        mid = (left + right) // 2

        if is_possible(mid, n, lamps):
            result = mid
            right = mid - 1
        else:
            left = mid + 1

    return result

n = int(input())
m = int(input())
lamps = list(map(int, input().split()))

result = find_min_height(n, m, lamps)

print(result)
