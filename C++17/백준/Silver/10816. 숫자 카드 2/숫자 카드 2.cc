#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int N;
    cin >> N;

    unordered_map<int, int> card_count;
    int card;

    for (int i = 0; i < N; ++i) {
        cin >> card;
        card_count[card]++;
    }

    int M;
    cin >> M;

    vector<int> queries(M);

    for (int i = 0; i < M; ++i) {
        cin >> queries[i];
    }

    for (int i = 0; i < M; ++i) {
        cout << card_count[queries[i]] << ' ';
    }

    cout << '\n';
    return 0;
}
