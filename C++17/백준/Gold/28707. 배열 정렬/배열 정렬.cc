#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vec1;
typedef vector<vec1> vec2;
typedef vector<vec2> vec3;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

struct State {
    vec1 arr;
    int cost;

    bool operator<(const State& other) const { return cost > other.cost; }
};
string vectorToString(const vec1& v) {
    string s;
    for (int num : v) {
        s += to_string(num) + ",";
    }
    return s;
}

int dijkstra(const vec1& A, const vec1& target, const vector<pair<pair<int, int>, int>>& operations) {
    priority_queue<State> pq;
    unordered_map<string, int> dist;

    pq.push({A, 0});
    dist[vectorToString(A)] = 0;

    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();

        string currentKey = vectorToString(current.arr);

        if (current.arr == target) {
            return current.cost;
        }

        if (current.cost > dist[currentKey]) continue;

        for (auto& op : operations) {
            int l = op.first.first;
            int r = op.first.second;
            int c = op.second;

            vec1 newArr = current.arr;
            swap(newArr[l], newArr[r]);

            string newKey = vectorToString(newArr);
            int newCost = current.cost + c;

            if (dist.find(newKey) == dist.end() || newCost < dist[newKey]) {
                dist[newKey] = newCost;
                pq.push({newArr, newCost});
            }
        }
    }

    return -1;
}

int main() {
    init();
    int N;
    cin >> N;

    vec1 A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int M;
    cin >> M;

    vector<pair<pair<int, int>, int>> operations(M);
    for (int i = 0; i < M; ++i) {
        int l, r, c;
        cin >> l >> r >> c;
        operations[i] = {{l - 1, r - 1}, c};
    }

    vec1 target = A;
    sort(target.begin(), target.end());

    int result = dijkstra(A, target, operations);

    cout << result << endl;

    return 0;
}