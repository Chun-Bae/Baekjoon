#include <iostream>

using namespace std;

int minOperations(int A, int B) {
    int count = 0;
    while (B > A) {
        if (B % 2 != 0) {
            if (B % 10 == 1)
                B /= 10;
            else
                return -1;
        } else
            B /= 2;

        count++;
    }

    if (A != B) {
        return -1;
    }
    return count + 1;
}

int main() {
    int A, B;
    cin >> A >> B;

    int result = minOperations(A, B);
    cout << result << endl;

    return 0;
}
