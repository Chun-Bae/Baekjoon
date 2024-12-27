def max_people_eating_hamburgers(N, K, table):
    people = []
    hamburgers = []

    for i in range(N):
        if table[i] == 'P':
            people.append(i)
        elif table[i] == 'H':
            hamburgers.append(i)

    max_eaters = 0
    h_idx = 0

    for p in people:
        while h_idx < len(hamburgers) and hamburgers[h_idx] < p - K:
            h_idx += 1  

        if h_idx < len(hamburgers) and hamburgers[h_idx] <= p + K:
            max_eaters += 1
            h_idx += 1

    return max_eaters

N, K = map(int, input().split())
table = input().strip()

result = max_people_eating_hamburgers(N, K, table)
print(result)