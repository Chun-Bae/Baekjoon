import sys

def reverse_words(S):
    result = []
    word = []
    inside_tag = False
    
    for char in S:
        if char == '<':
            if word:
                result.append(''.join(word[::-1]))
                word = []
            inside_tag = True
            result.append(char)
        elif char == '>':
            inside_tag = False
            result.append(char)
        elif inside_tag:
            result.append(char)
        elif char == ' ':
            result.append(''.join(word[::-1]))
            result.append(char)
            word = []
        else:
            word.append(char)
    
    if word:
        result.append(''.join(word[::-1]))
    
    return ''.join(result)

if __name__ == "__main__":
    S = sys.stdin.readline().strip()
    print(reverse_words(S))