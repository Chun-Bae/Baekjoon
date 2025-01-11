import sys

input = sys.stdin.read
data = input().splitlines()

n = int(data[0])

numbers = list(map(int, data[1:]))

numbers.sort()

sys.stdout.write('\n'.join(map(str, numbers)) + '\n')
