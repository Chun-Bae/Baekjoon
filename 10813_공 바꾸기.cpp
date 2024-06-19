#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int N, M;
    cin >> N >> M;

    vector<int> n(N + 1);

    for (int i = 1; i <= N; i++) n[i] = i;

    for (int i = 1; i <= M; i++){
        int a, b;
        cin >> a >> b;
        int tmp = n[a];
        n[a] = n[b];
        n[b] = tmp;
    }

    for (int i = 1; i <= N; i++) cout<<n[i]<<" ";

    return 0;
}