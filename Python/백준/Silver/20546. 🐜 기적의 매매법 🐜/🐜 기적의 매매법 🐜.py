def bnp_vs_timing(cash, prices):
    bnp_cash = cash
    bnp_stocks = 0

    for price in prices:
        if bnp_cash >= price:
            bnp_stocks += bnp_cash // price
            bnp_cash %= price

    bnp_total = bnp_cash + bnp_stocks * prices[-1]

    timing_cash = cash
    timing_stocks = 0
    up_days = 0
    down_days = 0

    for i in range(1, len(prices)):
        if prices[i] > prices[i - 1]:
            up_days += 1
            down_days = 0
        elif prices[i] < prices[i - 1]:
            down_days += 1
            up_days = 0
        else:
            up_days = 0
            down_days = 0

        if up_days >= 3 and timing_stocks > 0:
            timing_cash += timing_stocks * prices[i]
            timing_stocks = 0

        elif down_days >= 3 and timing_cash >= prices[i]:
            timing_stocks += timing_cash // prices[i]
            timing_cash %= prices[i]

    timing_total = timing_cash + timing_stocks * prices[-1]

    if bnp_total > timing_total:
        return "BNP"
    elif bnp_total < timing_total:
        return "TIMING"
    else:
        return "SAMESAME"

cash = int(input())
prices = list(map(int, input().split()))

print(bnp_vs_timing(cash, prices))
