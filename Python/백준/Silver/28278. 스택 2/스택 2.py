import sys
input = sys.stdin.read

def main():
    data = input().splitlines()
    n = int(data[0])

    stack = []
    result = []

    for i in range(1, n + 1):
        command = data[i]

        if command.startswith("1"):
            _, x = command.split()
            stack.append(int(x))

        elif command == "2":
            if stack:
                result.append(stack.pop())
            else:
                result.append(-1)

        elif command == "3":
            result.append(len(stack))

        elif command == "4":
            result.append(1 if not stack else 0)

        elif command == "5":
            if stack:
                result.append(stack[-1])
            else:
                result.append(-1)

    sys.stdout.write("\n".join(map(str, result)) + "\n")

if __name__ == "__main__":
    main()