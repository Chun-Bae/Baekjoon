#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore();

    string n, num;
    for (int i = 0; i < T; i++) {
        vector<string> numbers;

        int sum = 0;
        getline(cin, num);
        stringstream sstream(num);
        while (getline(sstream, n, ' ')) numbers.push_back(n);
        for (auto n : numbers) sum += stoi(n);
        cout << sum << endl;
    }
    return 0;
}