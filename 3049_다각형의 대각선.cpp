#include <iostream>
using namespace std;

int main() {
    int n, result;
    cin >> n;
    result = (n * (n - 1) * (n - 2) * (n - 3)) / (4 * 3 * 2 * 1);
    cout << result << endl;
    return 0;
}