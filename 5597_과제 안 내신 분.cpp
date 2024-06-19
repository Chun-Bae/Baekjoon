#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<bool> am(31, false);
    int n;
    am[0] = true;
    for (int i = 0; i < 28; i++) {
        cin >> n;
        if (!am[n]) am[n] = true;
    }
    for (int i = 0; i < 31; i++)
        if (!am[i]) cout << i << endl;
    return 0;
}