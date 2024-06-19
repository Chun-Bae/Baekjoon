#include <iostream>

using namespace std;

int main() {
    string arr;
    int count = 1;
    cin >> arr;
    for (auto& a : arr)
        if (a == ',') ++count;
    cout << count;
    return 0;
}