#include <bits/stdc++.h>

#include <iostream>
#include <vector>

#define MAX 100001
using namespace std;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

bool visited[MAX];
bool done[MAX];
vector<int> stu;
int cnt;

void dfs(int current) {
    visited[current] = true;
    int next = stu[current];
    if (!visited[next])
        dfs(next);
    else if (!done[next]) {
        for (int i = next; i != current; i = stu[i]) cnt++;
        cnt++;
    }
    done[current] = true;
    return;
}

int main() {
    init();
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        stu.resize(n + 1);
        for (int i = 1; i <= n; i++) cin >> stu[i];
        for (int i = 1; i <= n; i++)
            if (!visited[i]) dfs(i);

        cout << n - cnt << '\n';
        cnt = 0;
        memset(visited, false, sizeof(visited));
        memset(done, false, sizeof(done));
    }
    return 0;
}