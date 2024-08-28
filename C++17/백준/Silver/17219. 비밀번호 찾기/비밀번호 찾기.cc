#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
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
    int N, M;
    cin >> N >> M;

    unordered_map<string, string> password_map;

    for (int i = 0; i < N; i++) {
        string site, password;
        cin >> site >> password;
        password_map[site] = password;
    }

    for (int i = 0; i < M; i++) {
        string site;
        cin >> site;
        cout << password_map[site] << '\n';
    }

    return 0;
}