#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    int n, m;
    ll x, y;
    ll sum = 0;
    priority_queue<ll, vector<ll>, greater<ll>> A;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        A.push(a);
    }
    while (m--) {
        x = A.top();
        A.pop();
        y = A.top();
        A.pop();
        A.push(x + y);
        A.push(x + y);
    }
    while (!A.empty()) {
        ll a;
        a = A.top();
        A.pop();
        sum += a;
    }
    cout << sum;
    return 0;
}