def is_inside_circle(px, py, cx, cy, r):
    return (px - cx) ** 2 + (py - cy) ** 2 < r ** 2

T = int(input())
for _ in range(T):
    x1, y1, x2, y2 = map(int, input().split())
    n = int(input())
    count = 0
    for _ in range(n):
        cx, cy, r = map(int, input().split())
        start_inside = is_inside_circle(x1, y1, cx, cy, r)
        end_inside = is_inside_circle(x2, y2, cx, cy, r)
        if start_inside != end_inside:
            count += 1
    print(count)