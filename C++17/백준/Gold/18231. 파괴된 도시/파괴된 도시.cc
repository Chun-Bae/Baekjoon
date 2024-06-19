#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int N, M, K;
vector<vector<int>> graph(2005);
bool checked[2005] = {false}; // 파괴된 도시 정보 저장 배열
bool visit[2005] = {false}; // 파괴된 도시가 주어진 조건을 만족했는지 검사하는 배열
vector<int> bomb; // 폭탄 투하 도시 정보 저장 벡터

int main() {
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int node1, node2;
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    cin >> K;

    vector<int> destroy_cities(K);
    for (int i = 0; i < K; ++i) {
        cin >> destroy_cities[i];
        checked[destroy_cities[i]] = true; // 파괴된 도시의 정보를 저장
    }

    for (int i = 1; i <= N; i++) {
        bool check = false;

        if (checked[i]) {
            for (int j = 0; j < graph[i].size(); j++) {
                if (!checked[graph[i][j]]) {
                    check = true;
                    break;
                }
            }

            if (!check) {
                bomb.push_back(i);
                visit[i] = true;
                for (int j = 0; j < graph[i].size(); j++) {
                    visit[graph[i][j]] = true;
                }
            }
        }
    }

    bool wrong = false;
    for (int i = 1; i <= N; i++) {
        if (checked[i] && !visit[i]) {
            wrong = true;
            break;
        }
    }

    if (wrong) {
        cout << -1 << endl;
    } else {
        cout << bomb.size() << endl;
        sort(bomb.begin(), bomb.end());
        for (int i = 0; i < bomb.size(); i++) {
            cout << bomb[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
