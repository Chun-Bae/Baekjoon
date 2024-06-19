#include <iostream>

using namespace std;

int main() {
    int T;
    string str1, str2;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> str1 >> str2;
        cout << "Distances: ";
        for (int j = 0; j < str1.size(); j++) {
            if (str2[j] - str1[j] >= 0)
                cout << str2[j] - str1[j] << " ";
            else
                cout << 26 + str2[j] - str1[j] << " ";
        }
        cout << endl;
    }
    return 0;
}