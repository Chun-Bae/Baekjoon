#include <algorithm>
#include <iostream>
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
    int x;
    while (cin >> x) {
        x *= 10000000;
        int n;
        cin >> n;
        vector<int> blocks(n);

        for (int i = 0; i < n; i++) {
            cin >> blocks[i];
        }

        sort(blocks.begin(), blocks.end());

        int left = 0;
        int right = n - 1;
        int l1 = -1, l2 = -1;
        int maxDiff = -1;
        while (left < right) {
            int sum = blocks[left] + blocks[right];
            if (sum == x) {
                int diff = blocks[right] - blocks[left];
                if (diff > maxDiff) {
                    maxDiff = diff;
                    l1 = blocks[left];
                    l2 = blocks[right];
                }
                left++;
                right--;
            } else if (sum < x) {
                left++;
            } else {
                right--;
            }
        }

        if (l1 == -1) {
            cout << "danger" << endl;
        } else {
            cout << "yes " << l1 << " " << l2 << endl;
        }
    }

    return 0;
}