#include <iostream>
#include <vector>

using namespace std;

void init(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int N, M;
    cin >> N >> M;
    
    if (N == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> books(N);
    for (int i = 0; i < N; i++) {
        cin >> books[i];
    }

    int boxCount = 0;
    int currentBoxWeight = 0;

    for (int i = 0; i < N; i++) {
        if (currentBoxWeight + books[i] > M) {
            boxCount++;
            currentBoxWeight = 0;
        }
        currentBoxWeight += books[i];
    }
    
    if (currentBoxWeight > 0) {
        boxCount++;
    }

    cout << boxCount << endl;

    return 0;
}
