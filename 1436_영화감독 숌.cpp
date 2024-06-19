#include <iostream>

using namespace std;

bool is_sss(int sss) {
    string str = to_string(sss);    
    for (int i = 0; i < str.size() - 2; i++)
        if (str[i] == '6' && str[i + 1] == '6' && str[i + 2] == '6') return true;
    return false;
}

int main() {
    int sss = 665;
    int n;
    cin >> n;
    while (n) {
        sss++;
        if (is_sss(sss)) n--;
    }
    cout << sss << '\n';
    return 0;
}