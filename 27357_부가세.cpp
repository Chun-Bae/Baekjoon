#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
#define TAX 10000
int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N, X;
        double P = 0;
        cin >> N >> X;

        for (int p = 0; p < N; p++) {
            double price;
            cin >> price;
            P += price;
        }

        P *= 10000;
        double minCent = X ? X * TAX : P;
        double maxCent = (X + 1) * TAX - 1;

        double minF = floor(((minCent / P) - 1) * 100);
        double maxF = floor(((maxCent / P) - 1) * 100);
        cout << minF << " " << maxF << endl;
    }
    return 0;
}