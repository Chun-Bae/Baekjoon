def is_possible(limit, money, M):
    count = 1
    total = 0
    for cost in money:
        if total + cost > limit:
            count += 1
            total = cost
        else:
            total += cost
    return count <= M

def find_min_withdrawal(N, M, money):
    left = max(money)      
    right = sum(money)  
    answer = right

    while left <= right:
        mid = (left + right) // 2
        if is_possible(mid, money, M):
            answer = mid
            right = mid - 1
        else:
            left = mid + 1

    return answer

N, M = map(int, input().split())
money = [int(input()) for _ in range(N)]
print(find_min_withdrawal(N, M, money))