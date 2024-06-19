#include <iostream>

using namespace std;

int main() {
    string parity;
    while (1) {
        cin >> parity;
        if (parity == "#") break;
        int cnt_1 = 0;

        for (auto& p : parity) {            
            switch (p) {
                case '1':
                    cnt_1++;
                    break;
                case 'e':
                    if (cnt_1 % 2 == 0) p = '0';
                    if (cnt_1 % 2 == 1) p = '1';
                    cnt_1++;
                    break;
                case 'o':
                    if (cnt_1 % 2 == 0) p = '1';
                    if (cnt_1 % 2 == 1) p = '0';
                    cnt_1++;
                    break;

                default:
                    break;
            }
        }
        cout << parity << endl;
    }
    return 0;
}