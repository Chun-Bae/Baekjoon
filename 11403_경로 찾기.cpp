#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> g[100];
int visit[100];

void dfs(int x) {
    for (int i = 0; i < g[x].size(); i++) {
        if (!visit[g[x][i]]) {
            visit[g[x][i]] = 1;
            dfs(g[x][i]);
        }
    }
}

int main() {
    int T, n;
    cin >> T;
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < T; j++) {
            cin >> n;
            if (n) g[i].push_back(j);
        }
    }
    
    for (int i = 0; i < T; i++) {
        memset(visit, 0, sizeof(visit));
        dfs(i);
        for (int j = 0; j < T; j++) cout << visit[j] << " ";
        cout << "\n";
    }

    return 0;
}