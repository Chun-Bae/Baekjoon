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

    vec1 heights(N);
    for (int i = 0; i < N; i++) {
        cin >> heights[i];
    }

    stack<int> s;
    ll result = 0;

    for (int i = 0; i < N; i++) {
        while (!s.empty() && s.top() <= heights[i]) s.pop();
        result += s.size();
        s.push(heights[i]);
    }

    cout << result << endl;
    return 0;
}