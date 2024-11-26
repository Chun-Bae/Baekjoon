def is_acceptable(password):
    vowels = "aeiou"
    has_vowel = False
    consecutive_vowels = 0
    consecutive_consonants = 0
    prev_char = ""
    
    for i, char in enumerate(password):
        if char in vowels:
            has_vowel = True
            consecutive_vowels += 1
            consecutive_consonants = 0
        else:
            consecutive_consonants += 1
            consecutive_vowels = 0
        
        if consecutive_vowels == 3 or consecutive_consonants == 3:
            return False
        
        if i > 0 and char == prev_char and char not in "eo":
            return False
        
        prev_char = char
    
    return has_vowel

while True:
    password = input().strip()
    if password == "end":
        break
    if is_acceptable(password):
        print(f"<{password}> is acceptable.")
    else:
        print(f"<{password}> is not acceptable.")

