word = input()
min_word = None
for i in range(1, len(word) - 1):
    for j in range(i + 1, len(word)):
        part1 = word[:i][::-1]
        part2 = word[i:j][::-1]
        part3 = word[j:][::-1]
        new_word = part1 + part2 + part3
        if min_word is None or new_word < min_word:
            min_word = new_word

print(min_word)
