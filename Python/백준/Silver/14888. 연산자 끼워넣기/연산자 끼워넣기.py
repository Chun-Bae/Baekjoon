import sys

n = int(input())
numbers = list(map(int, input().split()))
add, sub, mul, div = map(int, input().split())

max_value = -int(1e9)
min_value = int(1e9)

def dfs(index, result, add, sub, mul, div):
    global max_value, min_value
    
    if index == n:
        max_value = max(max_value, result)
        min_value = min(min_value, result)
        return
    
    if add > 0:
        dfs(index + 1, result + numbers[index], add - 1, sub, mul, div)
    if sub > 0:
        dfs(index + 1, result - numbers[index], add, sub - 1, mul, div)
    if mul > 0:
        dfs(index + 1, result * numbers[index], add, sub, mul - 1, div)
    if div > 0:
        if result < 0:
            dfs(index + 1, -(-result // numbers[index]), add, sub, mul, div - 1)
        else:
            dfs(index + 1, result // numbers[index], add, sub, mul, div - 1)

dfs(1, numbers[0], add, sub, mul, div)

print(max_value)
print(min_value)
