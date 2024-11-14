#include <algorithm>
#include <iostream>
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
vec2 subordinates;
vec1 praise;

void propagatePraise(int employee) {
    for (int sub : subordinates[employee]) {
        praise[sub] += praise[employee];
        propagatePraise(sub);
    }
}

int main() {
    init();

    int n, m;
    cin >> n >> m;

    subordinates.resize(n + 1);
    praise.resize(n + 1, 0);

    int boss;
    cin >> boss;

    for (int i = 2; i <= n; ++i) {
        cin >> boss;
        subordinates[boss].push_back(i);
    }

    for (int i = 0; i < m; ++i) {
        int employee, amount;
        cin >> employee >> amount;
        praise[employee] += amount;
    }

    propagatePraise(1);

    for (int i = 1; i <= n; ++i) cout << praise[i] << " ";
    cout << endl;

    return 0;
}
