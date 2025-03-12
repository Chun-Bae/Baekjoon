import sys

def max_subarray_sum(arr):
    max_sum = -float('inf')  
    current_sum = 0
    
    for num in arr:
        current_sum = max(num, current_sum + num) 
        max_sum = max(max_sum, current_sum) 
    
    return max_sum

def main():
    t = int(sys.stdin.readline().strip())  
    results = []
    
    for _ in range(t):
        n = int(sys.stdin.readline().strip())  
        arr = list(map(int, sys.stdin.readline().split()))  
        results.append(str(max_subarray_sum(arr)))  
    
    print("\n".join(results))

if __name__ == "__main__":
    main()
