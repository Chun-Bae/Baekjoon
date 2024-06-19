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
    string str;
    string result;
    int cnt_0 = 0, cnt_1 = 0;
    cin >> str;
    for (auto s : str) s - '0' ? cnt_1++ : cnt_0++;
    cnt_0 /= 2;
    cnt_1 /= 2;
    int size = str.size();
    for (int i = size - 1; i >= 0; i--) {
        if (str[i] == '0') {
            str[i] = 'x';
            cnt_0--;
        }
        if (cnt_0 == 0) break;
    }
    for (int i = 0; i < size; i++) {
        if (str[i] == '1') {
            str[i] = 'x';
            cnt_1--;
        }
        if (cnt_1 == 0) break;
    }
    
    for (auto s : str)
        if (s != 'x') cout << s;

    return 0;
}