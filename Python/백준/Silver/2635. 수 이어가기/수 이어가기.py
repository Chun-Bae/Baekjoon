def generate_sequence(first, second):
    sequence = [first, second]
    while sequence[-2] - sequence[-1] >= 0:
        sequence.append(sequence[-2] - sequence[-1])
    return sequence

def find_longest_sequence(start):
    max_length = 0
    best_sequence = []

    for second in range(1, start + 1):
        sequence = generate_sequence(start, second)
        if len(sequence) > max_length:
            max_length = len(sequence)
            best_sequence = sequence

    return max_length, best_sequence

if __name__ == "__main__":
    first_number = int(input())

    max_len, best_seq = find_longest_sequence(first_number)

    print(max_len)
    print(" ".join(map(str, best_seq)))
