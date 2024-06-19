#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string n, str, all_str = "";
    int sum = 0;
    while (1) {
        cin >> str;
        if (cin.eof()) break;
        str.erase(remove(str.begin(), str.end(), ' '), str.end());
        all_str += str;
    }
    stringstream sstream(all_str);
    while (getline(sstream, n, ',')) sum += stoi(n);
    
    cout << sum<<endl;
    return 0;
}