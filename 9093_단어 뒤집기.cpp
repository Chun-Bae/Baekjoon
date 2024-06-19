#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    int T;
    string str;

    cin >> T;
    cin.ignore();
    for (int i = 0; i < T; i++) {
        getline(cin, str);
        stringstream sstream(str);
        while (getline(sstream, str, ' ')) {
            for (int j = str.size() - 1; j >= 0; j--) {
                cout << str[j];
            }
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}