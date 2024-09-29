#include <algorithm>
#include <iostream>
#include <stack>
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
    int N;
    cin >> N;

    vec1 A(N);
    vec1 answer(N, -1);
    stack<int> s;  // index

    for (int i = 0; i < N; ++i) cin >> A[i];

    for (int i = 0; i < N; ++i) {
        while (!s.empty() && A[s.top()] < A[i]) {
            answer[s.top()] = A[i];
            s.pop();
        }
        s.push(i);
    }

    for (int i = 0; i < N; ++i) cout << answer[i] << " ";

    return 0;
}