#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> A(10);
    vector<int> B(10);
    int n, count_a = 0, count_b = 0;
    for (int i = 0; i < 10; i++) {
        cin >> n;
        A[i] = n;
    }
    for (int i = 0; i < 10; i++) {
        cin >> n;
        B[i] = n;
    }
    for (int i = 0; i < 10; i++) {
        if (A[i] - B[i] > 0) count_a++;
        if (A[i] - B[i] < 0) count_b++;
    }
    if (count_a > count_b) cout << "A" << endl;
    if (count_a < count_b) cout << "B" << endl;
    if (count_a == count_b) cout << "D" << endl;
    return 0;
}