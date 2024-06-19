#include <iostream>

using namespace std;

int main() {
    int minute = 0;
    int n;
    for (int i = 0; i < 4; i++) {
        cin >> n;
        minute += n;
    }
    cout << minute / 60 << '\n' << minute % 60 << endl;

    return 0;
}