#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    int count = 0;
    cin >> N >> M;
    vector<int> jumong(N);
    for (int i = 0; i < N; i++) {
        cin >> jumong[i];
    }
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            if (jumong[i] + jumong[j] == M) count++;
    cout << count;
    return 0;
}