def next_greater_number(X):
    # string을 각 자리수 리스트로 변환
    digits = list(str(X))
    n = len(digits)
    
	
    i = n - 2
    # 반전 구간 찾기 (혹은  증가 부분, 오른쪽부터 읽어야함(최초))
    while i >= 0 and digits[i] >= digits[i + 1]:
        i -= 1
	# digit[i] = 5, i = 1
    # print("i",digits[i])
	
    if i == -1:
        return 0
    
    # 하강 구간에서 반전구간의 시작점보다 낮아지는 부분 (오른쪽부터 읽어야함(최초))
    j = n - 1
    while digits[j] <= digits[i]:
        j -= 1
    # digit[j] = 6, j = 2
    # print("j",digits[j])
    
    # 서로 위치를 바꿔줌
	# 5 <-> 6
	# 156 -> 165
    digits[i], digits[j] = digits[j], digits[i]
    # print("swap",digits)
    
    # [::-1] 역순 -> 16 + 5(reverse)
    digits = digits[:i + 1] + digits[i + 1:][::-1]
    # print("digits[:i + 1]",digits[:i + 1])
    # print("digits[i + 1:][::-1]",digits[i + 1:][::-1])
    # print("reverse",digits)
    return int(''.join(digits))


X = int(input())
result = next_greater_number(X)
print(result)
