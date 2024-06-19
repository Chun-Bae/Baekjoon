#include <iostream>

using namespace std;

typedef long long ll;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int n;
    cin >> n;
    string str;
    for (int i = 1; i <= n; i++) {
        cin >> str;
        cout << "String #" << i << '\n';
        for (auto& s : str) {
            s = s - 'A';
            s = s + 1;
            s = s % 26;
            s = s + 'A';
        }
        cout<<str<<'\n'<<'\n';
    }
    return 0;
}