#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string num1, num2, r_result;
    int result;
    cin >> num1 >> num2;
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    result = stoi(num1) + stoi(num2);
    r_result = to_string(result);
    reverse(r_result.begin(), r_result.end());

    cout << stoi(r_result) << endl;

    return 0;
}