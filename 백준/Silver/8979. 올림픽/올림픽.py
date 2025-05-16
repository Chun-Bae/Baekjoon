N, K = map(int, input().split())

countries = []
for _ in range(N):
    nation_info = list(map(int, input().split()))
    countries.append(nation_info)

countries.sort(key=lambda x: (-x[1],-x[2],-x[3]))

rank=1
nation_rank = dict()
nation_rank[countries[0][0]] = 1

for i in range(1,N):
    prev = countries[i-1]
    curr = countries[i]
    if curr[1:] == prev[1:]:
        nation_rank[curr[0]] = rank
    else:
        rank = i + 1
        nation_rank[curr[0]] = rank

print(nation_rank[K])