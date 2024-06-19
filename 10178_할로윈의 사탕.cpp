#include <iostream>

using namespace std;

int main() {
    int N;
    int candy, member;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> candy >> member;
        cout << "You get " << candy / member << " piece(s) and your dad gets " << candy % member << " piece(s)." << endl;
    }
    return 0;
}