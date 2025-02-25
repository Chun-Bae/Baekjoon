import sys

def next_permutation(seq):
    n = len(seq)
    
    i = n - 1
    while i > 0 and seq[i - 1] >= seq[i]:
        i -= 1
    
    if i == 0:
        print(-1)
        return

    j = n - 1
    while seq[i - 1] >= seq[j]:
        j -= 1
    
    seq[i - 1], seq[j] = seq[j], seq[i - 1]

    seq[i:] = reversed(seq[i:])
    
    print(*seq)

n = int(sys.stdin.readline().strip())
sequence = list(map(int, sys.stdin.readline().split()))

next_permutation(sequence)