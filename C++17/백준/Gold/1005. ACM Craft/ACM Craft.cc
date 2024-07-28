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
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> D(N + 1);
        vector<vector<int>> adj(N + 1);
        vector<int> indegree(N + 1);
        vector<int> time(N + 1);
        
        for (int i = 1; i <= N; i++) {
            cin >> D[i];
        }
        
        for (int i = 0; i < K; i++) {
            int X, Y;
            cin >> X >> Y;
            adj[X].push_back(Y);
            indegree[Y]++;
        }
        
        int W;
        cin >> W;
        
        queue<int> q;
        
        for (int i = 1; i <= N; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                time[i] = D[i];
            }
        }
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            
            for (int next : adj[cur]) {
                indegree[next]--;
                time[next] = max(time[next], time[cur] + D[next]);
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        cout << time[W] << "\n";
    }
    return 0;
}
