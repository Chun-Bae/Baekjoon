import sys

def evaluate_postfix(expression, values):
    stack = []
    
    for char in expression:
        if 'A' <= char <= 'Z':  
            stack.append(values[char])
        else:  
            b = stack.pop()
            a = stack.pop()
            if char == '+':
                stack.append(a + b)
            elif char == '-':
                stack.append(a - b)
            elif char == '*':
                stack.append(a * b)
            elif char == '/':
                stack.append(a / b)
    
    return stack[0]

if __name__ == "__main__":
    n = int(sys.stdin.readline().strip())
    expression = sys.stdin.readline().strip()
    values = {}
    
    for i in range(n):
        values[chr(ord('A') + i)] = int(sys.stdin.readline().strip())
    
    result = evaluate_postfix(expression, values)
    print(f"{result:.2f}")
