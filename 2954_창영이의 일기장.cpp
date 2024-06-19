#include <iostream>

using namespace std;

int main() {
    string str;
    getline(cin, str);
    for (int i = 0; i < str.size() - 2; i++)
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            if (str[i + 1] = 'p') str.erase(i, 2);
    cout << str;
    return 0;
}