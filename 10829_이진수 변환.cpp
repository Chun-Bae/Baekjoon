#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long n;
    string bin = "";
    cin >> n;
    while (n) {
        bin += char((n % 2) + '0');
        n /= 2;
    }
    reverse(bin.begin(),bin.end());
    cout << bin;
    return 0;
}