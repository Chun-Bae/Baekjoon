N = int(input())
calendar = [0] * 366

# 일정의 날짜 범위에 해당하는 날마다 일정 개수를 증가
for _ in range(N):
    S, E = map(int, input().split())
    for day in range(S, E + 1):
        calendar[day] += 1

area = 0
width = 0
height = 0

for day in range(1, 366):
    if calendar[day] > 0:
        width += 1
        height = max(height, calendar[day])
    else:
        # 현재 연속된 일정 구간이 끝났을 때 면적 계산
        area += width * height
        width = 0
        height = 0

# 마지막 일정이 달력의 끝(365일)까지 간 경우 처리
area += width * height

print(area)