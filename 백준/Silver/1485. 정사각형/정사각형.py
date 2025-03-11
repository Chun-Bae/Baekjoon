import sys
from itertools import combinations

def distance_squared(p1, p2):
    """두 점 (x1, y1), (x2, y2) 사이의 거리 제곱을 반환"""
    return (p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2

def is_square(points):
    """네 개의 점이 정사각형을 만들 수 있는지 확인"""
    dists = sorted([distance_squared(p1, p2) for p1, p2 in combinations(points, 2)])
    
    # 변의 길이 (4개)와 대각선의 길이 (2개)를 확인
    return (dists[0] == dists[1] == dists[2] == dists[3] and  # 네 개의 변 길이 동일
            dists[4] == dists[5] and                         # 두 개의 대각선 길이 동일
            2 * dists[0] == dists[4])                        # 대각선 길이 = 변 길이 * 2

def main():
    input = sys.stdin.read
    data = input().splitlines()
    
    T = int(data[0])
    index = 1
    results = []
    
    for _ in range(T):
        points = [tuple(map(int, data[index + i].split())) for i in range(4)]
        index += 4
        results.append("1" if is_square(points) else "0")
    
    print("\n".join(results))

if __name__ == "__main__":
    main()