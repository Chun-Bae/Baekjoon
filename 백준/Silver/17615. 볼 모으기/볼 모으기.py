def count_moves(balls, color, direction):
    n = len(balls)
    count = 0
    if direction == 'left':
        i = 0
        while i < n and balls[i] == color:
            i += 1
        for j in range(i, n):
            if balls[j] == color:
                count += 1
    else:  
        i = n - 1
        while i >= 0 and balls[i] == color:
            i -= 1
        for j in range(0, i + 1):
            if balls[j] == color:
                count += 1
    return count

def solve():
    import sys
    input = sys.stdin.readline
    n = int(input())
    balls = input().strip()

    if 'R' not in balls or 'B' not in balls:
        print(0)
        return

    min_moves = min(
        count_moves(balls, 'R', 'left'),
        count_moves(balls, 'R', 'right'),
        count_moves(balls, 'B', 'left'),
        count_moves(balls, 'B', 'right')
    )
    print(min_moves)

solve()