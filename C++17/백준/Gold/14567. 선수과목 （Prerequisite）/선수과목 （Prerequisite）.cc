#include <iostream>
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
    vector<vector<int>> graph(N + 1);
    vector<int> indegree(N + 1, 0);
    for (int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }
    vector<int> semester(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            semester[i] = 1;
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            // i에 대해서 next 노드
            int next = graph[i][j];
            if (semester[i] != 0) {
                semester[next] = max(semester[next], semester[i] + 1);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << semester[i] << " ";
    }

    return 0;
}