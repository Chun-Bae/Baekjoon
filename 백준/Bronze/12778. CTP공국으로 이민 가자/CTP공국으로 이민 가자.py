T = int(input())

for _ in range(T):
    M, kind = input().split()
    M = int(M)
    data = input().split()

    if kind == 'C': 
        result = [str(ord(ch) - ord('A') + 1) for ch in data]
    elif kind == 'N':  
        result = [chr(int(num) + ord('A') - 1) for num in data]

    print(' '.join(result))