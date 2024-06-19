#include <iostream>

using namespace std;

int twenty2ten(string ABC) {
    int result = 0;
    result = (ABC[0] - 65) * 26 * 26;
    result += (ABC[1] - 65) * 26;
    result += (ABC[2] - 65);
    return result;
}

int main() {
    string str, partABC, part123;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> str;
        partABC = str.substr(0, 3);
        part123 = str.substr(4, 4);
        if (abs(twenty2ten(partABC) - stoi(part123)) <= 100)
            cout << "nice" << endl;
        else
            cout << "not nice" << endl;
    }

    return 0;
}