from collections import Counter

def frequency_sort(n, c, sequence):
    count = Counter(sequence) 
    unique_order = list(dict.fromkeys(sequence))  
    
    sorted_sequence = sorted(sequence, key=lambda x: (-count[x], unique_order.index(x)))
    
    print(*sorted_sequence)

n, c = map(int, input().split())
sequence = list(map(int, input().split()))

frequency_sort(n, c, sequence)
