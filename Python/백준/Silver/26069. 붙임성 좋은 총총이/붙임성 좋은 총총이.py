n = int(input())
meetings = [input().split() for _ in range(n)]

rainbow_dancers = set()
rainbow_dancers.add("ChongChong")  

for a, b in meetings:
    if a in rainbow_dancers or b in rainbow_dancers:
        rainbow_dancers.add(a)
        rainbow_dancers.add(b)

print(len(rainbow_dancers))