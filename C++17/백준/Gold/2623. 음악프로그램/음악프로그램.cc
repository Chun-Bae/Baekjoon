#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();

    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N + 1);
    vector<int> indegree(N + 1, 0);

    for (int i = 0; i < M; i++) {
        int n;
        cin >> n;
        vector<int> singers(n);
        for (int j = 0; j < n; j++) {
            cin >> singers[j];
        }
        for (int j = 0; j < n - 1; j++) {
            graph[singers[j]].push_back(singers[j + 1]);
            indegree[singers[j + 1]]++;
        }
    }

    queue<int> q;
    vector<int> result;

    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        result.push_back(current);

        for (int next : graph[current]) {
            indegree[next]--;
            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    if (result.size() == N) {
        for (int singer : result) {
            cout << singer << "\n";
        }
    } else {
        cout << 0 << "\n";
    }

    return 0;
}
