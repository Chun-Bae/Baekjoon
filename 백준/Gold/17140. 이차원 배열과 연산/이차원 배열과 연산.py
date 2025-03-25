from collections import Counter

def operate_R(arr):
    max_len = 0
    new_arr = []
    for row in arr:
        count = Counter([x for x in row if x != 0])
        sorted_items = sorted(count.items(), key=lambda x: (x[1], x[0]))
        new_row = []
        for num, cnt in sorted_items:
            new_row.extend([num, cnt])
        max_len = max(max_len, len(new_row))
        new_arr.append(new_row)
    
    for i in range(len(new_arr)):
        new_arr[i] = new_arr[i][:100]
        new_arr[i] += [0] * (max_len - len(new_arr[i]))
    
    return new_arr

def operate_C(arr):
    transposed = list(map(list, zip(*arr)))
    transposed = operate_R(transposed)
    return list(map(list, zip(*transposed)))

def solution():
    r, c, k = map(int, input().split())
    A = [list(map(int, input().split())) for _ in range(3)]

    time = 0
    while time <= 100:
        if r-1 < len(A) and c-1 < len(A[0]) and A[r-1][c-1] == k:
            print(time)
            return
        if len(A) >= len(A[0]):
            A = operate_R(A)
        else:
            A = operate_C(A)
        time += 1

    print(-1)

solution()