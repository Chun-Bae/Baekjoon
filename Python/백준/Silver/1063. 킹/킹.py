move_dict = {
    "R": (0, 1),
    "L": (0, -1),
    "B": (-1, 0),
    "T": (1, 0),
    "RT": (1, 1),
    "LT": (1, -1),
    "RB": (-1, 1),
    "LB": (-1, -1)
}

king, stone, n = input().split()
n = int(n)
moves = [input().strip() for _ in range(n)]

def pos_to_coord(pos):
    return (int(pos[1]) - 1, ord(pos[0]) - ord('A'))

def coord_to_pos(coord):
    return chr(coord[1] + ord('A')) + str(coord[0] + 1)

king_pos = pos_to_coord(king)
stone_pos = pos_to_coord(stone)

for move in moves:
    dx, dy = move_dict[move]
    new_king_pos = (king_pos[0] + dx, king_pos[1] + dy)

    if 0 <= new_king_pos[0] < 8 and 0 <= new_king_pos[1] < 8:
        # 돌의 위치와 겹치는 경우
        if new_king_pos == stone_pos:
            new_stone_pos = (stone_pos[0] + dx, stone_pos[1] + dy)

            if 0 <= new_stone_pos[0] < 8 and 0 <= new_stone_pos[1] < 8:
                stone_pos = new_stone_pos
                king_pos = new_king_pos
        else:
            king_pos = new_king_pos

print(coord_to_pos(king_pos))
print(coord_to_pos(stone_pos))
