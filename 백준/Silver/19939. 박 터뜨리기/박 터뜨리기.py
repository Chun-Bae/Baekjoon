def min_diff(N, K):
    min_required = K * (K + 1) // 2
    if N < min_required:
        return -1

    remaining = N - min_required

    # K개의 서로 다른 숫자에 대해서 최대한 균등하게 추가할 수 있음
    # 1~K 로 배분하고, 거기다 남은 remaining을 나눠서
    # 가장 작은 수는 1 + 추가, 가장 큰 수는 K + 추가
    # => 차이 = (K + q) - (1 + q) = K - 1

    # 하지만 남은 공을 K개에 다 못나누는 경우(즉, 나머지가 남는 경우), 일부 큰 수에만 더해짐 → 차이 1 증가
    q, r = divmod(remaining, K)
    if r == 0:
        return K - 1
    else:
        return K

N, K = map(int, input().split())
print(min_diff(N, K))