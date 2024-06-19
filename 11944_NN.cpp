#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string N;
    int M;
    cin >> N >> M;
    string result = "";
    for (int i = 0; i < stoi(N); i++) result += N;
    int minimum = min(int(result.size()), M);
    cout << result.substr(0, minimum) << endl;
    return 0;
}
