import math
N = int(input())
sizes = list(map(int, input().split()))  # S, M, L, XL, XXL, XXXL
T, P = map(int, input().split())
tshirt_bundles = sum(math.ceil(size / T) for size in sizes)

pen_bundles = N // P
pen_singles = N % P
print(tshirt_bundles)
print(pen_bundles, pen_singles)