#include <iostream>

using namespace std;

int main() {
    int N;
    string str;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> str;
        for (auto& s : str)
            if (s < 'a') s += 32;
        cout << str << endl;
    }
    return 0;
}