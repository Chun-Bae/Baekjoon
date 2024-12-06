from collections import deque

def can_make_equal(a,b,c):
    total = a+b+c
    if total % 3 != 0:
        return 0
    
    source = tuple(sorted([a,b,c]))
    visited = set([source])
    queue = deque([source])
    
    while queue:
        x,y,z = queue.popleft()
        
        if x==y==z:
            return  1
        
        for nx,ny in [(x,y),(x,z),(y,z)]:
            if nx!=ny:
                smaller, larger = min(nx,ny), max(nx,ny)
                new_smaller = smaller + smaller
                new_larger = larger - smaller
                new_group = sorted([new_smaller,new_larger, total-new_smaller-new_larger])
                
                if tuple(new_group) not in visited:
                    visited.add(tuple(new_group))
                    queue.append(tuple(new_group))
                    
                    
    return 0

a,b,c = map(int,input().split())
print(can_make_equal(a,b,c))
                