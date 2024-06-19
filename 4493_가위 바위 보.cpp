#include <iostream>

using namespace std;

int main() {
    int T, N, count1, count2;
    char P1, P2;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        count1 = 0, count2 = 0;
        for (int j = 0; j < N; j++) {
            cin >> P1 >> P2;
            if (P1 == 'R') {
                if (P2 == 'S') count1++;
                if (P2 == 'P') count2++;
            } else if (P1 == 'S') {
                if (P2 == 'R') count2++;
                if (P2 == 'P') count1++;
            } else if (P1 == 'P') {
                if (P2 == 'S') count2++;
                if (P2 == 'R') count1++;
            }
        }
        if (count1 > count2)
            cout << "Player 1" << endl;
        else if (count1 < count2)
            cout << "Player 2" << endl;
        else
            cout << "TIE" << endl;
    }
    return 0;
}