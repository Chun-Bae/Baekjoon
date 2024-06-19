#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

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

    for (int i = 1; i <= N; i++) {
        string str;
        vector<int> pan(26, 0);
        getline(cin, str);

        for (auto s : str) {
            if ((s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z')) {
                if (s >= 'a') s -= ('a' - 'A');
                pan[s - 'A']++;
            }
        }

        int check = 3;
        for (auto p : pan)
            if (check > p) check = p;

        if (check == 0) cout << "Case " << i << ": Not a pangram";
        if (check == 1) cout << "Case " << i << ": Pangram!";
        if (check == 2) cout << "Case " << i << ": Double pangram!!";
        if (check == 3) cout << "Case " << i << ": Triple pangram!!!";
        cout << endl;
    }

    return 0;
}