#include <algorithm>
#include <iostream>
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

    unordered_map<string, int> pocketmon2number;
    vector<string> number2pocketmon(N + 1);

    for (int i = 1; i <= N; i++) {
        string pocketmon;
        cin >> pocketmon;
        pocketmon2number[pocketmon] = i;
        number2pocketmon[i] = pocketmon;
    }

    for (int i = 0; i < M; i++) {
        string query;
        cin >> query;
        if (isdigit(query[0])) {
            int num = stoi(query);
            cout << number2pocketmon[num] << '\n';
        } else {
            cout << pocketmon2number[query] << '\n';
        }
    }
    return 0;
}