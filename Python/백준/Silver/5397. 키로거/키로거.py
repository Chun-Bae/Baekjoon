import sys
from collections import deque

def solve_keylogger(test_cases):
    results = []
    for case in test_cases:
        left_stack = deque()
        right_stack = deque()

        for char in case:
            if char == '<':
                if left_stack:
                    right_stack.appendleft(left_stack.pop())
            elif char == '>':
                if right_stack:
                    left_stack.append(right_stack.popleft())
            elif char == '-':
                if left_stack:
                    left_stack.pop()
            else:
                left_stack.append(char)

        results.append(''.join(left_stack) + ''.join(right_stack))
    return results

input = sys.stdin.read
data = input().splitlines()
T = int(data[0])
test_cases = data[1:]

results = solve_keylogger(test_cases)
sys.stdout.write("\n".join(results) + "\n")