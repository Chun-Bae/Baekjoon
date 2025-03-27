import math
a1, b1 = map(int, input().split())
a2, b2 = map(int, input().split())
numerator = a1 * b2 + a2 * b1
denominator = b1 * b2
gcd = math.gcd(numerator, denominator)
numerator //= gcd
denominator //= gcd
print(numerator, denominator)