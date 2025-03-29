n = int(input())  
roads = list(map(int, input().split())) 
prices = list(map(int, input().split()))  

total_cost = 0 
min_price = prices[0] 

for i in range(n - 1):
    total_cost += min_price * roads[i]
    if prices[i + 1] < min_price:
        min_price = prices[i + 1]

print(total_cost)