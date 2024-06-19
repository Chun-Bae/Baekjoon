#include <iostream>

using namespace std;

int main() {
    int state = 0;
    int input, output;
    int max = state;
    for (int i = 0; i < 4; i++) {
        cin >> output >> input;
        state -= output;
        state += input;
        if(max < state)
            max = state;
    }
    cout << max;
    return 0;
}