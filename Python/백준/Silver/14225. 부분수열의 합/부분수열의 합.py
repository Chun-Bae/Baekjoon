def find_smallest_unreachable_sum(n, s):
    s.sort()
    target = 1  

    for num in s:
        if num > target:
            break  
        target += num  
    
    return target

n = int(input())
s = list(map(int, input().split()))

print(find_smallest_unreachable_sum(n, s))
