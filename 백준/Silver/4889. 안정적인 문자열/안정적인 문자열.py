import sys

def min_operations_to_stable(s):
    stack = []
    operations = 0
    
    for char in s:
        if char == '{':
            stack.append(char)
        else: 
            if stack:
                stack.pop()
            else:
                operations += 1  # '}'를 '{'로 바꿔야 함
                stack.append('{')
    
    operations += len(stack) // 2  # 남은 '{' 개수를 2개씩 짝지어 변경
    return operations

def main():
    case_number = 1
    while True:
        s = sys.stdin.readline().strip()
        if '-' in s:
            break
        print(f"{case_number}. {min_operations_to_stable(s)}")
        case_number += 1

if __name__ == "__main__":
    main()
