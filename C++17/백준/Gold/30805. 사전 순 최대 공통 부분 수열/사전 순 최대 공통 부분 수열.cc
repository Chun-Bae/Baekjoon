#include <iostream>
#include <vector>

using namespace std;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

vector<int> input(int size) {
    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    return arr;
}

vector<int> LCS(const vector<int>& arrA, const vector<int>& arrB) {
    int idxA = 0, idxB = 0;
    vector<int> result;

    while (idxA < arrA.size() && idxB < arrB.size()) {
        int cur = -1, maxA, maxB;

        for (int i = idxA; i < arrA.size(); i++) {
            for (int j = idxB; j < arrB.size(); j++) {
                if (arrA[i] == arrB[j] && arrA[i] > cur) {
                    cur = arrA[i];
                    maxA = i;
                    maxB = j;
                }
            }
        }
        if (cur == -1) break;

        result.push_back(cur);
        idxA = maxA + 1;
        idxB = maxB + 1;
    }

    return result;
}

int main() {
    init();

    int numA, numB;
    cin >> numA;
    vector<int> arrA = input(numA);
    cin >> numB;
    vector<int> arrB = input(numB);

    vector<int> results = LCS(arrA, arrB);

    cout << results.size() << '\n';
    for (int num : results) {
        cout << num << ' ';
    }
    cout << '\n';
    return 0;
}
