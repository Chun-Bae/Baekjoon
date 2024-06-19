#include <iostream>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int max = s1.size() > s2.size() ? s1.size() : s2.size();
    int min = s1.size() < s2.size() ? s1.size() : s2.size();
    s1.size() < s2.size() ? s1.insert(0, max - min, '0') : s2.insert(0, max - min, '0');
    
    for (int i = 0; i < max; i++) {
        cout << s1[i] - '0' + s2[i] - '0';
    }
    return 0;
}