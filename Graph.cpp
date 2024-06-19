#include <iostream>
using namespace std;

class Graph {
    int V; // 정점의 수
    int **adj; // 인접 행렬 포인터
public:
    Graph(int V); // 생성자
    void addEdge(int v, int w); // 간선 추가
    void printGraph(); // 그래프 출력
};

Graph::Graph(int V) {
    this->V = V;
    adj = new int*[V];
    for (int i = 0; i < V; ++i) {
        adj[i] = new int[V];
        for (int j = 0; j < V; ++j)
            adj[i][j] = 0;
    }
}

void Graph::addEdge(int v, int w) {
    adj[v][w] = 1; // v에서 w로의 간선 추가
    adj[w][v] = 1; // 무방향 그래프인 경우, w에서 v로도 추가
}

void Graph::printGraph() {
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j)
            cout << adj[i][j] << " ";
        cout << "\n";
    }
}

int main() {
    Graph g(5); // 5개의 정점을 가진 그래프
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();

    return 0;
}
