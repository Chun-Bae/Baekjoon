#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> mirror;
    string str;
    int T, opt;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> str;
        mirror.push_back(str);
    }
    cin >> opt;

    switch (opt) {
        case 1:
            for (int i = 0; i < T; i++) {
                cout << mirror[i] << endl;
            }
            break;
        case 2:
            for (int i = 0; i < T; i++) {
                for (int j = T - 1; j >= 0; j--) {
                    cout << mirror[i][j];
                }
                cout << endl;
            }
            break;
        case 3:
            for (int i = T - 1; i >= 0; i--) {
                for (int j = 0; j < T; j++) {
                    cout << mirror[i][j];
                }
                cout << endl;
            }
            break;
        default:
            break;
    }

    return 0;
}