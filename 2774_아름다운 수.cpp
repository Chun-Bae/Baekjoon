#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T, count;
    string num;
    cin >> T;
    for (int i = 0; i < T; i++) {
        vector<bool> beautiful(10, false);
        count = 0;
        cin >> num;
        for (auto& n : num) {
            int number = int(n) - 48;
            if (!beautiful[number]) beautiful[number] = true;
        }
        for (int j = 0; j < 10; j++)
            if (beautiful[j]) count++;
        cout << count << '\n';
    }

    return 0;
}