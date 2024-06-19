#include <iostream>
using namespace std;

int main() {
    string str;
    int upper, lower, number, empty;

    for (int i = 0; i < 100; i++) {
        getline(cin, str);
        if (cin.eof()) return 0;
        upper = 0, lower = 0, number = 0, empty = 0;
        for (auto& s : str) {
            if (s >= 'A' && s <= 'Z') upper++;
            if (s >= 'a' && s <= 'z') lower++;
            if (s >= '0' && s <= '9') number++;
            if (s == ' ') empty++;
        }
        cout << lower << " " << upper << " " << number << " " << empty << endl;
    }

    return 0;
}