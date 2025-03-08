from itertools import permutations

def count_unique_numbers(n, k, cards):
    unique_numbers = set()
    
    for perm in permutations(cards, k):
        num = ''.join(map(str, perm))
        unique_numbers.add(num)
    
    return len(unique_numbers)

n = int(input().strip())
k = int(input().strip())
cards = [input().strip() for _ in range(n)]

print(count_unique_numbers(n, k, cards))