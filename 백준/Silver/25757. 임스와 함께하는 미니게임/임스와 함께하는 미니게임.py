N, game_type = input().split()
N = int(N)

game_requirements = {'Y': 2, 'F': 3, 'O': 4}
people_needed = game_requirements[game_type]

participants = set()

for _ in range(N):
    name = input()
    participants.add(name)

max_games = len(participants) // (people_needed - 1)  

print(max_games)