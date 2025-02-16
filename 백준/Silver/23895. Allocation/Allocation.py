def max_houses(T, test_cases):
    results = []
    
    for t in range(T):
        N, B = test_cases[t][0]  
        prices = sorted(test_cases[t][1]) 
        
        count = 0
        total_cost = 0
        
        for price in prices:
            if total_cost + price <= B:
                total_cost += price
                count += 1
            else:
                break
        
        results.append(f"Case #{t+1}: {count}")
    
    return results

T = int(input().strip())
test_cases = []

for _ in range(T):
    N, B = map(int, input().split())
    prices = list(map(int, input().split()))
    test_cases.append(((N, B), prices))

for result in max_houses(T, test_cases):
    print(result)