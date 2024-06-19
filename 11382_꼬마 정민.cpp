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
    ll a, b, c;
    cin >> a >> b >> c;
    cout << a + b + c;
    
    return 0;
}