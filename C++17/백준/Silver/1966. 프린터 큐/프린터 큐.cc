#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;

        queue<pair<int, int>> q;
        priority_queue<int> pq;

        for (int i = 0; i < N; i++) {
            int priority;
            cin >> priority;
            q.push({priority, i});
            pq.push(priority);
        }

        int print_order = 0;
        while (!q.empty()) {
            int current_priority = q.front().first;
            int current_index = q.front().second;
            q.pop();

            if (current_priority == pq.top()) {
                pq.pop();
                print_order++;
                if (current_index == M) {
                    cout << print_order << '\n';
                    break;
                }
            } else {
                q.push({current_priority, current_index});
            }
        }
    }
    return 0;
}
