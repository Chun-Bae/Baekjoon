#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<bool> seating(101, false);
    int N, seat, count = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> seat;
        seating[seat] ? count++ : seating[seat] = true;
    }
    cout << count;
    return 0;
}