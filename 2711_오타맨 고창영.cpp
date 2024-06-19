#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int idx;
        string spelling;

        cin >> idx >> spelling;
        spelling.erase(idx-1,1);

        cout << spelling << endl;
    }

    return 0;
}