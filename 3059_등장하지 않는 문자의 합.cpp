#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, sum;
    string S;
    cin >> N;
    for (int i = 0; i < N; i++) {
        vector<bool> alphabet(26, true);
        cin >> S;
        sum = 0;
        for (auto& s : S) alphabet[s - 65] = false;
        for (int j = 0; j < 26; j++)
            if (alphabet[j]) sum += (j + 65);
        cout << sum << endl;
    }

    return 0;
}