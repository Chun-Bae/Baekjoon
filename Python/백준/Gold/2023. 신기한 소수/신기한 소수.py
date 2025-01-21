def is_prime(num):
    if num < 2:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

def find_amazing_primes(current, length, n):
    if length == n:
        print(current)
        return

    for digit in range(1, 10, 2):
        next_num = current * 10 + digit
        if is_prime(next_num):
            find_amazing_primes(next_num, length + 1, n)

def main():
    n = int(input().strip())

    for prime in [2, 3, 5, 7]:
        find_amazing_primes(prime, 1, n)

if __name__ == "__main__":
    main()