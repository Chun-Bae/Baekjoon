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
    cin >> str;
    int n;
    int cnt = 0;
    cin >> n;
    while (n--) {
        string search_ring;
        cin >> search_ring;
        for (int i = 0; i < search_ring.size(); i++) {
            bool is_str = true;
            string cmp = "";
            for (int j = 0; j < str.size(); j++) cmp += search_ring[(i + j) % (search_ring.size())];
            if (cmp == str) {
                cnt++;
                break;
            }
        }
    }
    cout << cnt;
    return 0;
}