#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
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
    int M, N;
    cin >> M >> N;

    vec2 universes(M, vec1(N));

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> universes[i][j];
        }
    }

    map<vec1, int> normalized_count;

    for (int i = 0; i < M; ++i) {
        vec1 compressed(N);

        vec1 temp = universes[i];
        sort(temp.begin(), temp.end());

        for (int j = 0; j < N; ++j) {
            compressed[j] = lower_bound(temp.begin(), temp.end(), universes[i][j]) - temp.begin();
        }

        normalized_count[compressed]++;
    }

    int result = 0;

    for (const auto& entry : normalized_count) {
        int count = entry.second;
        if (count > 1) {
            result += count * (count - 1) / 2;
        }
    }

    cout << result << '\n';

    return 0;
}