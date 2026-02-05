#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string input_t, output_t;
        cin >> input_t >> output_t;
        int i = 0;
        for (; i < input_t.size(); i++)
            if (input_t[i] != output_t[i])
                break;
        if (i == input_t.size())
            cout << "OK" << endl;
        else
            cout << "ERROR" << endl;
    }
    return 0;
}