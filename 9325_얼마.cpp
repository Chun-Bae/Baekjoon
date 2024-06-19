#include <iostream>

using namespace std;

int main() {
    int N, option, q, p, price;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> price;
        cin >> option;
        for (int j = 0; j < option; j++) {
            cin >> q >> p;
            price += q * p;
        }
        cout << price << endl;
    }
    return 0;
}