#include <iostream>

using namespace std;

int main() {
    int T, distance;
    string s1, s2;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> s1 >> s2;
        distance = 0;
        for (int j = 0; j < s1.size(); j++) {
            if (s1[j] - s2[j]) distance++;
        }
        cout << "Hamming distance is " << distance << "." << endl;
    }
    return 0;
}