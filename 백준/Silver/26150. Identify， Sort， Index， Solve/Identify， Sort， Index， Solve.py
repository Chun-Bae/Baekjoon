n = int(input())
probloms = []

for _ in range(n):
    s, i, d = input().split()
    i = int(i)
    d = int(d)
    probloms.append((i,s,d))
probloms.sort()

result = []

for i,s,d in probloms:
    char = s[d-1]
    if char.islower():
        char = char.upper()

    result.append(char)

print("".join(result))
