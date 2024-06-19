#include <iostream>
#include <vector>

using namespace std;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();

    int n, k;
    int p;
    cin >> n >> k;
    vector<int> original(n + 1);
    vector<int> bring(n + 1);
    vector<int> tmp(n + 1);
    for (int i = 1; i <= n; i++) cin >> original[i];
    for (int i = 1; i <= n; i++) cin >> bring[i];

    while (k--) {
        for (int i = 1; i <= n; i++) tmp[bring[i]] = original[i];
        original = tmp;
    }
    for (int i = 1; i <= n; i++) cout << original[i] << " ";
    return 0;
}