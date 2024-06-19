#include <iostream>

using namespace std;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}
int main() {
    init();
    string str;
    while (1) {
        int sum = 0;
        getline(cin, str);
        if (str == "#") break;

        for (int i = 1; i <= str.size(); i++) {
            if(str[i-1]== ' ') continue;
            sum += (str[i - 1] - 'A' + 1) * i;
        }
        cout << sum << '\n';
    }

    return 0;
}