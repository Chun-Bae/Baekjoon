#include <iostream>

using namespace std;

typedef long long ll;

void init(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main(){
    init();
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                cnt++;
            } else {
                cnt--;
            }
            if (cnt < 0) {
                break;
            }
        }
        if (cnt == 0) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }   
    return 0;
}