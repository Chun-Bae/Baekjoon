def calculate_bracket_value(s):
    stack = []
    temp = 1
    result = 0
    prev = ''

    for i, ch in enumerate(s):
        if ch == '(':
            stack.append(ch)
            temp *= 2
        elif ch == '[':
            stack.append(ch)
            temp *= 3
        elif ch == ')':
            if not stack or stack[-1] != '(':
                return 0
            if prev == '(':
                result += temp
            stack.pop()
            temp //= 2
        elif ch == ']':
            if not stack or stack[-1] != '[':
                return 0
            if prev == '[':
                result += temp
            stack.pop()
            temp //= 3
        prev = ch

    if stack:
        return 0
    return result

s = input().strip()
print(calculate_bracket_value(s))