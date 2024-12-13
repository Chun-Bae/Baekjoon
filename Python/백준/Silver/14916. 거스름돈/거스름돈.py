def min_coins(change):
    for five_coins in range(change // 5, -1, -1):
        remaining = change - (five_coins * 5)
        if remaining % 2 == 0:
            two_coins = remaining // 2
            return five_coins + two_coins
    return -1

n = int(input())
print(min_coins(n))
