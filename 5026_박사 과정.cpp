#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    int T, plus;
    string str, n;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> str;
        if (str == "P=NP")
            cout << "skipped" << endl;
        else {
            vector<string> num;
            plus = 0;
            stringstream sstream(str);
            while (getline(sstream, n, '+')) num.push_back(n);
            for (auto n : num) plus += stoi(n);
            cout << plus << endl;
        }
    }

    return 0;
}