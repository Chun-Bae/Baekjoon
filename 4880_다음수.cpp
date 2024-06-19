#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int a, b, c;
    while (1) {
        cin >> a >> b >> c;
        if (!a && !b && !c) break;
       
        if (b - a == c - b) {
            cout << "AP " << c + (b - a) << endl;
       
        } else if (b / a == c / b && a * c == b * b) { 
            cout << "GP " << c * (b / a) << endl; 
        }
    }

    return 0;
}
