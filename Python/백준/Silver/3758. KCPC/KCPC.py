def calculate_rank(n, k, t, m, logs):
    teams = {i: {'scores': [0] * k, 'submissions': 0, 'last_submission': 0} for i in range(1, n + 1)}

    for time, (team_id, problem_id, score) in enumerate(logs, start=1):
        teams[team_id]['submissions'] += 1
        teams[team_id]['last_submission'] = time
        problem_index = problem_id - 1
        teams[team_id]['scores'][problem_index] = max(teams[team_id]['scores'][problem_index], score)

    team_results = []
    for team_id, data in teams.items():
        total_score = sum(data['scores'])
        submissions = data['submissions']
        last_submission = data['last_submission']
        team_results.append((total_score, submissions, last_submission, team_id))

    team_results.sort(key=lambda x: (-x[0], x[1], x[2]))

    for rank, (_, _, _, team_id) in enumerate(team_results, start=1):
        if team_id == t:
            return rank


T = int(input())
results = []

for _ in range(T):
    n, k, t, m = map(int, input().split())
    logs = [tuple(map(int, input().split())) for _ in range(m)]
    results.append(calculate_rank(n, k, t, m, logs))

# Output results
for result in results:
    print(result)
