#include <iostream>

using namespace std;

typedef long long ll;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int custom_pow(int b, int n, int p, int a) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result = result * b;
        result = result % p;
    
        cout << "r: " << result << endl;
    }
    result = result / (a % p);
    return result;
}

int main() {
    init();
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int a, b, n, p;
        cin >> a >> b >> n >> p;
        int result = custom_pow(b, n, p, a);
        cout << result << endl;
    }

    return 0;
}