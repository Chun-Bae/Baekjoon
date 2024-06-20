#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, pair<int, int>>> graph(10001);
vector<int> parent(10001);

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

// 루트 부모 찾는 함수
int findRoot(int x) {
    if (x == parent[x]) return x;
    return parent[x] = findRoot(parent[x]);
}

// a와 b의 루트 노드를 찾아서 b의 루트노드를 a의 루트노드로 설정
void unionNodes(int a, int b) {
    a = findRoot(a);
    b = findRoot(b);
    parent[b] = a;
}

// 루트 부모가 같은지 확인
bool hasSameRoot(int a, int b) {
    a = findRoot(a);
    b = findRoot(b);
    return a == b;
}

int main() {
    init();
    int V, E;
    int result = 0;
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        graph.push_back({C, {A, B}});
    }
    sort(graph.begin(), graph.end());
    
    // 부모 초기화
    for (int i = 1; i <= V; i++) parent[i] = i;
    
    // 간선을 하나씩 확인하며
    for (int i = 0; i < graph.size(); i++) {
        int cost = graph[i].first;
        int a = graph[i].second.first;
        int b = graph[i].second.second;
        if (!hasSameRoot(a, b)) {
            // 같지 않으니까 합쳐주고 비용 추가
            // 스패닝 트리 형성
            unionNodes(a, b);
            result += cost;
        }
    }
    
    cout << result << endl;
    return 0;
}
