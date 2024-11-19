#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vec1;
typedef vector<vec1> vec2;
typedef vector<vec2> vec3;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();

    int N, Q;
    cin >> N >> Q;

    vector<int> A(N + 1);
    unordered_map<int, int> freq;

    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        freq[A[i]]++;
    }

    while (Q--) {
        int type, param;
        cin >> type >> param;

        if (type == 1) {
            int x = param;
            bool found = false;

            if (x == 0) {
                if (freq.count(0) && freq[0] >= 1 && N >= 2) {
                    found = true;
                }
            } else {
                for (auto& elem : freq) {
                    int value = elem.first;
                    int count = elem.second;

                    if (value == 0 || x % value != 0) continue;

                    int other = x / value;
                    if (other != value) {
                        if (freq.count(other) && freq[other] > 0) {
                            found = true;
                            break;
                        }
                    } else {
                        if (count > 1) {
                            found = true;
                            break;
                        }
                    }
                }
            }
            cout << (found ? 1 : 0) << '\n';
        } else if (type == 2) {
            int i = param;
            if (A[i] != 0) {
                freq[A[i]]--;
                if (freq[A[i]] == 0) freq.erase(A[i]);
                A[i] = 0;
                freq[0]++;
            }
        }
    }

    return 0;
}
