from collections import defaultdict

def calculate_outfit_combinations(test_cases):
    results = []

    for n, clothes in test_cases:
        if n == 0:
            results.append(0)
            continue

        category_count = defaultdict(int)
        
        for name, category in clothes:
            category_count[category] += 1

        combinations = 1
        for count in category_count.values():
            combinations *= (count + 1)

        results.append(combinations - 1)

    return results

if __name__ == "__main__":
    t = int(input())  
    test_cases = []

    for _ in range(t):
        n = int(input())  
        clothes = [input().split() for _ in range(n)]
        test_cases.append((n, clothes))

    results = calculate_outfit_combinations(test_cases)

    for result in results:
        print(result)