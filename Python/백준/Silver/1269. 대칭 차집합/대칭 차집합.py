import sys
    
input = sys.stdin.read
data = input().splitlines()

_, _ = map(int, data[0].split()) 
set_a = set(map(int, data[1].split())) 
set_b = set(map(int, data[2].split())) 

symmetric_diff = set_a.symmetric_difference(set_b)
print(len(symmetric_diff))