from collections import deque

def check_snack_order(n, line):
    line = deque(line)
    stack = []
    cur = 1

    while line or stack:
        if line and line[0] == cur:
            line.popleft()
            cur += 1
        elif stack and stack[-1] == cur:
            stack.pop()
            cur += 1
        elif line:
            stack.append(line.popleft())
        else:
            break

    if cur == n + 1:
        print("Nice")
    else:
        print("Sad")

n = int(input())
line = list(map(int, input().split()))
check_snack_order(n, line)