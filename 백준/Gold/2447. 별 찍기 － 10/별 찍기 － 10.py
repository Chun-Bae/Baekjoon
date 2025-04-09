def draw_star(n):
    if n == 1:
        return ["*"]
    
    sub = draw_star(n // 3)
    result = []
    
    for i in range(3):
        for line in sub:
            if i == 1:
                result.append(line + " " * (n // 3) + line)
            else:
                result.append(line * 3)
    return result

N = int(input())
pattern = draw_star(N)
for line in pattern:
    print(line)