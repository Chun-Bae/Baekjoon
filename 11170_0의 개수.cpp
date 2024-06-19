#include <iostream>

using namespace std;

int main() {
    int T,n, start, end, count;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> start >> end;
        count = 0;
        for (int j = start; j <= end; j++) {
            n = j;
            if (!n) ++count;
            while (n) {
                if (!(n % 10)) ++count;
                n /= 10;
            }
        }
        cout << count << endl;
    }
    return 0;
}