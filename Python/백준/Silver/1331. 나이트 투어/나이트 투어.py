def is_valid_knight_tour(tour):
    def position_to_index(pos):
        return ord(pos[0]) - ord('A'), int(pos[1]) - 1
    knight_moves = [
        (2, 1), (2, -1), (-2, 1), (-2, -1),
        (1, 2), (1, -2), (-1, 2), (-1, -2)
    ]

    if len(tour) != 36:
        return "Invalid"

    if len(set(tour)) != 36:
        return "Invalid"

    for i in range(35):
        current = position_to_index(tour[i])
        next_pos = position_to_index(tour[i + 1])

        if (next_pos[0] - current[0], next_pos[1] - current[1]) not in knight_moves:
            return "Invalid"

    start = position_to_index(tour[0])
    end = position_to_index(tour[-1])

    if (end[0] - start[0], end[1] - start[1]) not in knight_moves:
        return "Invalid"

    return "Valid"

tour = [input().strip() for _ in range(36)]
print(is_valid_knight_tour(tour))
