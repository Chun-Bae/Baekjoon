#include <iostream>
#include <vector>

using namespace std;

int main() {
    int K, P, M, number, notAttend;
    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> P >> M;
        vector<int> seatings(M + 1, 0);
        notAttend = 0;
        for (int j = 0; j < P; j++) {
            cin >> number;
            seatings[number]++;
        }
        for (int j = 1; j <= M; j++) {
            if (seatings[j] > 1) notAttend += seatings[j] - 1;
        }
        cout << notAttend << endl;
    }
    return 0;
}