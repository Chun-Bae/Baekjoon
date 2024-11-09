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

int main() {
    init();
    ll N;
    cin >> N;

    if (N % 7 == 0 || N % 7 == 2)
        cout << "CY" << endl;
    else
        cout << "SK" << endl;

    return 0;
}