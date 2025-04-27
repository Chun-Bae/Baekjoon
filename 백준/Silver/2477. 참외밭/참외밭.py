K = int(input())
sides = [tuple(map(int, input().split())) for _ in range(6)]

max_width = 0
max_height = 0
max_width_idx = 0
max_height_idx = 0

for i in range(6):
    direction, length = sides[i]
    if direction == 1 or direction == 2:  
        if length > max_width:
            max_width = length
            max_width_idx = i
    elif direction == 3 or direction == 4:  
        if length > max_height:
            max_height = length
            max_height_idx = i

small_width = abs(sides[(max_width_idx + 5) % 6][1] - sides[(max_width_idx + 1) % 6][1])
small_height = abs(sides[(max_height_idx + 5) % 6][1] - sides[(max_height_idx + 1) % 6][1])

area = (max_width * max_height) - (small_width * small_height)

print(area * K)