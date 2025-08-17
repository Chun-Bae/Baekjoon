#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int count;
    int T;                   // 테스트 케이스
    int N, M;                // 정점, 간선
    vector<vector<int>> G;   // 방향 그래프
    vector<vector<bool>> R;  // 방향 그래프의 경로 존재 여부

    cin >> T;
    while (T--) {
        cin >> N >> M;

        G.clear();
        R.clear();
        G.resize(N + 1);
        R.resize(N + 1, vector<bool>(N + 1, false));

        count = 0;

        // 초기 그래프 정보
        for (int i = 0; i < M; i++) {
            int start, end;
            cin >> start >> end;
            G[start].push_back(end);
        }


        // BFS를 통해 갈 수 있는 정점을 모두 표시
        vector<int> visited(N + 1, 0);
        queue<int> q;

        for(int i=1; i<N+1; i++){
            fill(visited.begin(), visited.end(), 0);
            visited[i]=true;
            q.push(i);

            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(auto v : G[u]){
                    if(!visited[v]){
                        visited[v]=true;
                        q.push(v);
                    }
                }
            }
            
            for(int j=1; j<N+1; j++){
                if(i==j) continue;
                if(visited[j]){
                    R[i][j]=true;
                    count++;
                }
            }
        }
        // 출력
        // for(int i=1; i<N+1; i++){
        //     for(int j=1;j<N+1; j++){
        //         cout<<R[i][j] << " ";
        //     }
        //     cout<<endl;
        // }
        cout<<count<<endl;
    }

    return 0;
}