#include <iostream>

using namespace std;

int main() {
    int count, max_count;
    char before;
    string str;
    for (int i = 0; i < 3; i++) {
        count = 1;
        max_count = 1; 
        before = ' ';
        cin >> str;
        for (auto& s : str) {
            if (before == s) {
                count++;
                if (count > max_count) max_count = count;
            } else {
                count = 1;
            }
            before = s;
        }
        
        cout << max_count << '\n';
    }

    return 0;
}
