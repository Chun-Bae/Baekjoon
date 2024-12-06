from itertools import combinations

def count_subsequences(N,S,numbers):
    count = 0
    
    for size in range(1,N+1):
        for subset in combinations(numbers,size):
            if sum(subset) == S:
                count += 1
                
    return count

N,S = map(int, input().split())

numbers = list(map(int, input().split()))

print(count_subsequences(N,S,numbers))