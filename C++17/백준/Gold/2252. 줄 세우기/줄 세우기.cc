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
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N + 1);
    vector<int> indegree(N + 1, 0);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        indegree[B]++;
    }

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> result;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        result.push_back(cur);
        for (int next : adj[cur]) {
            indegree[next]--;
            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    for (int student : result) {
        cout << student << " ";
    }
    cout << '\n';
    return 0;
}