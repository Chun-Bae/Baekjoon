#include <algorithm>
#include <cmath>
#include <iomanip>
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

void hanoi(int n, int from, int to, int aux) {
    if (n == 1) {
        cout << from << " " << to << "\n";
        return;
    }
    hanoi(n - 1, from, aux, to);
    cout << from << " " << to << "\n";
    hanoi(n - 1, aux, to, from);
}

int main() {
    init();
    int N;
    cin >> N;
    string result = to_string(pow(2, N));
    int decimalPos = result.find('.');
    result = result.substr(0, decimalPos);

    int i = result.length() - 1;
    while (i >= 0 && result[i] == '0') {
        result[i] = '9';
        i--;
    }
    if (i >= 0) {
        result[i] -= 1;
    }
    cout << result << "\n";
    
    if (N <= 20) {
        hanoi(N, 1, 3, 2);
    }
    return 0;
}