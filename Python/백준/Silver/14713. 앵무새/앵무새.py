from collections import deque

def is_possible(N, sentences, L):
    parrots = [deque(sentence.split()) for sentence in sentences]

    words = L.split()

    for word in words:
        found = False

        for parrot in parrots:
            if parrot and parrot[0] == word:
                parrot.popleft()
                found = True
                break

        if not found:
            return "Impossible"

    for parrot in parrots:
        if parrot:
            return "Impossible"

    return "Possible"

N = int(input())
sentences = [input().strip() for _ in range(N)]
L = input().strip()
print(is_possible(N, sentences, L))