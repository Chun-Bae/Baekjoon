#include <iostream>

using namespace std;

bool operation(int a, int b, string ope) {
    if (!ope.compare(">")) return a > b;
    else if (!ope.compare(">=")) return a >= b;
    else if (!ope.compare("<")) return a < b;
    else if (!ope.compare("<=")) return a <= b;
    else if (!ope.compare("!=")) return a != b;
    else if (!ope.compare("==")) return a == b;
    else return true;
}

int main() {
    int a, b;
    string ope;
    int i = 1;
    while(1) {
        cin >> a >> ope >> b;
        if (!ope.compare("E")) break;
        cout << "Case " << i++ << ": " << boolalpha << operation(a, b, ope) << '\n';
    }
    return 0;
}