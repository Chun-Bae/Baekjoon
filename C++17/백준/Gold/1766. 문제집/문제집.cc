#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int N, M;
    cin >> N >> M;
    adj.resize(N + 1);
    vector<int> indegree(N + 1, 0);
    
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        indegree[B]++;
    }
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            pq.push(i);
        }
    }
    
    vector<int> result;
    while (!pq.empty()) {
        int current = pq.top();
        pq.pop();
        result.push_back(current);
        
        for (int next : adj[current]) {
            indegree[next]--;
            if (indegree[next] == 0) {
                pq.push(next);
            }
        }
    }
    
    for (int problem : result) {
        cout << problem << " ";
    }
    
    return 0;
}
