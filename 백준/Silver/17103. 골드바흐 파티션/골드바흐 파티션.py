import sys

def sieve(limit):
    """ 에라토스테네스의 체를 사용하여 limit 이하의 모든 소수를 판별 """
    is_prime = [True] * (limit + 1)
    is_prime[0] = is_prime[1] = False  # 0과 1은 소수가 아님

    for i in range(2, int(limit ** 0.5) + 1):
        if is_prime[i]:
            for j in range(i * i, limit + 1, i):
                is_prime[j] = False
    
    return is_prime

def count_goldbach_partitions(n, is_prime):
    """ 주어진 짝수 n에 대한 골드바흐 파티션 개수를 구함 """
    count = 0
    for p in range(2, n // 2 + 1):
        if is_prime[p] and is_prime[n - p]:
            count += 1
    return count

def main():
    input = sys.stdin.read
    data = input().split()
    
    T = int(data[0])  
    numbers = list(map(int, data[1:T + 1])) 
    
    max_n = max(numbers)
    is_prime = sieve(max_n)

    results = [str(count_goldbach_partitions(n, is_prime)) for n in numbers]
    sys.stdout.write("\n".join(results) + "\n")

if __name__ == "__main__":
    main()