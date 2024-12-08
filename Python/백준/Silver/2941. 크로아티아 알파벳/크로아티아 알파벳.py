croatian_alphabets = ["c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="]
word = input().strip()
for cro_alpha in croatian_alphabets:
    word = word.replace(cro_alpha, "*") 
print(len(word))