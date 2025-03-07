import sys

n, q = map(int, sys.stdin.readline().split())
s = list(sys.stdin.readline().strip())

def count_groups(sub_s):
    count = 0
    length = len(sub_s)
    i = 0
    while i < length:
        count += 1  
        j = i
        while j + 1 < length and sub_s[j] == sub_s[j + 1]:
            j += 1
        i = j + 1  
    return count

for _ in range(q):
    query = list(map(int, sys.stdin.readline().split()))
    
    if query[0] == 1:  # 1 l r: 부분 문자열에서 알파벳 묶음 개수 계산
        l, r = query[1] - 1, query[2]
        print(count_groups(s[l:r]))
    
    elif query[0] == 2:  # 2 l r: 부분 문자열 알파벳 변경
        l, r = query[1] - 1, query[2]
        for i in range(l, r):
            s[i] = chr(((ord(s[i]) - ord('A') + 1) % 26) + ord('A'))
