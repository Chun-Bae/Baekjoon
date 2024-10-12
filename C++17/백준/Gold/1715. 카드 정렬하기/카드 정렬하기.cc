#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vec1;
typedef vector<vec1> vec2;
typedef vector<vec2> vec3;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int N;
    cin >> N;

    priority_queue<int, vec1, greater<int>> pq;

    for (int i = 0; i < N; i++) {
        int card;
        cin >> card;
        pq.push(card);
    }

    int total_comparisons = 0;
    while (pq.size() > 1) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        int sum = first + second;
        total_comparisons += sum;

        pq.push(sum);
    }

    cout << total_comparisons << endl;

    return 0;
}