#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> FBI;
    string str;
    for (int i = 1; i <= 5; i++) {
        cin >> str;
        if (str.size() >= 3) {
            for (int j = 0; j <= str.size() - 3; j++) {
                if (str.substr(j, 3) == "FBI") {
                    FBI.push_back(i);
                    break;
                }
            }
        }
    }
    if (!FBI.size())
        cout << "HE GOT AWAY!" << endl;
    else {
        for (int i = 0; i < FBI.size(); i++) {
            cout << FBI[i] << " ";
        }
    }
    return 0;
}