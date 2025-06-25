T=int(input())

for _ in range(T):
    N = int(input())
    prices= list(map(int,input().split()))

    max_price=0
    profit=0
    for price in reversed(prices):
        if max_price < price:
            max_price=price
        
        profit += (max_price-price)
    
    print(profit)