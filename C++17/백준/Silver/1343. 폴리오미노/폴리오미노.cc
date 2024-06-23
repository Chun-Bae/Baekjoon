#include <iostream>

using namespace std;

typedef long long ll;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

string polyomino(string str) {
    int count = 0;
    for (int i = 0; i < str.size() + 1; i++) {
        if (str[i] == 'X')
            count++;
        else {
            if (count % 2 == 1) return "-1";
            if (count % 4 == 0) {
                for (int j = 0; j < count; j++) {
                    str[i - j - 1] = 'A';
                }
            } else if (count % 4 == 2) {
                str[i - 1] = 'B';
                str[i - 2] = 'B';
                for (int j = 0; j < count - 2; j++) {
                    str[(i - 2 - 1) - j] = 'A';
                }
            }

            count = 0;
        }
    }
    return str;
}

int main() {
    init();
    string str;
    cin >> str;
    cout << polyomino(str) << '\n';
    return 0;
}
