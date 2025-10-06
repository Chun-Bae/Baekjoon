#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> truth(N + 1);
    vector<int> record(N + 1);

    for (int i = 0; i < M; i++) {
        int v, u;
        cin >> v >> u;
        truth[u].push_back(v);
    }

    for (int i = 1; i <= N; i++) {
        queue<int> q;
        vector<bool> visited(N + 1, 0);
        int hack = 0;
        q.push(i);
        visited[i] = 1;
        while (!q.empty()) {
            int dst = q.front();
            q.pop();

            for (int k = 0; k < truth[dst].size(); k++) {
                int next = truth[dst][k];

                if (visited[next] == 0) {
                    visited[next] = 1;
                    q.push(next);
                    hack++;
                }
            }
        }
        record[i] = hack;
    }
    int max_hack = *max_element(record.begin(), record.end());
    for (int i = 1; i <= N; i++) {
        if (max_hack == record[i])
            cout << i << " ";
    }

    return 0;
}