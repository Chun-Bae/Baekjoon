#include <iostream>

using namespace std;

int main() {
    string s1, s2;
    int N;
    cin >> N;
    cin >> s1 >> s2;
    if (N % 2 == 0) {
        if (s1.compare(s2))
            cout << "Deletion failed" << endl;
        else
            cout << "Deletion succeeded" << endl;
    } else {
        for (auto& s : s1) {
            if (s == '0')
                s = '1';
            else
                s = '0';
        }
        if (s1.compare(s2))
            cout << "Deletion failed" << endl;
        else
            cout << "Deletion succeeded" << endl;
    }
    return 0;
}