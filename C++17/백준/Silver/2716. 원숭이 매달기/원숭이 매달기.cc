#include <iostream>
#include <string>
using namespace std;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int N;
    cin >> N;
    cin.ignore();

    for (int i = 0; i < N; i++) {
        string S;
        getline(cin, S);

        int level = 0, maxlevel = 0;
        for (char c : S) {
            if (c == '[') {
                level++;
                if (level > maxlevel) maxlevel = level;
            } else if (c == ']') {
                level--;
            }
        }

        int result = 1;
        for (int j = 0; j < maxlevel; j++) {
            result *= 2;
        }

        cout << result << endl;
    }

    return 0;
}
