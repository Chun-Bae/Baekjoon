import sys

def main():
    N, M = map(int, sys.stdin.readline().split())
    scores = list(map(int, sys.stdin.readline().split()))

    max_score = 0
    best_id = float('inf')

    for _ in range(M):
        data = sys.stdin.readline().split()
        exam_id = int(data[0])
        answers = data[1:]

        total_score = sum(scores[i] for i in range(N) if answers[i] == 'O')

        if total_score > max_score or (total_score == max_score and exam_id < best_id):
            max_score = total_score
            best_id = exam_id

    print(best_id, max_score)

if __name__ == "__main__":
    main()
    