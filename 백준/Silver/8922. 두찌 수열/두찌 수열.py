import sys

def ducci_sequence(n, sequence):
    seen = set()
    
    while True:
        if all(x == 0 for x in sequence):
            return "ZERO"
        
        seq_tuple = tuple(sequence)
        if seq_tuple in seen:
            return "LOOP"
        seen.add(seq_tuple)
        
        sequence = [abs(sequence[i] - sequence[(i + 1) % n]) for i in range(n)]

if __name__ == "__main__":
    T = int(sys.stdin.readline().strip())
    
    for _ in range(T):
        n = int(sys.stdin.readline().strip())
        sequence = list(map(int, sys.stdin.readline().split()))
        print(ducci_sequence(n, sequence))
