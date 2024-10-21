#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
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
int N;
vec1 population;
vec2 adj;
vector<bool> selected;

bool isConnected(vec1& area) {
    vector<bool> visited(N + 1, false);
    queue<int> q;

    visited[area[0]] = true;
    q.push(area[0]);

    int count = 1;
    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : adj[current]) {
            if (!visited[neighbor] && find(area.begin(), area.end(), neighbor) != area.end()) {
                visited[neighbor] = true;
                q.push(neighbor);
                count++;
            }
        }
    }

    return count == area.size();
}

int calculateDifference() {
    vec1 area1, area2;

    for (int i = 1; i <= N; i++) {
        if (selected[i])
            area1.push_back(i);
        else
            area2.push_back(i);
    }

    if (area1.empty() || area2.empty()) return -1;
    if (!isConnected(area1) || !isConnected(area2)) return -1;

    int pop1 = 0, pop2 = 0;
    for (int i : area1) pop1 += population[i];
    for (int i : area2) pop2 += population[i];

    return abs(pop1 - pop2);
}
int main() {
    init();
    cin >> N;
    population.resize(N + 1);
    adj.resize(N + 1);
    selected.resize(N + 1);

    for (int i = 1; i <= N; i++) cin >> population[i];
    for (int i = 1; i <= N; i++) {
        int count;
        cin >> count;
        for (int j = 0; j < count; j++) {
            int neighbor;
            cin >> neighbor;
            adj[i].push_back(neighbor);
        }
    }

    int result = 1e9;
    for (int i = 1; i < (1 << N); i++) {
        for (int j = 1; j <= N; j++) {
            selected[j] = (i & (1 << (j - 1))) != 0;
        }

        int diff = calculateDifference();
        if (diff != -1) {
            result = min(result, diff);
        }
    }

    if (result == 1e9)
        cout << -1 << endl;
    else
        cout << result << endl;

    return 0;
}