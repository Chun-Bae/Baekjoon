#include <iostream>
#include <vector>

using namespace std;

int main() {
    int min, max;
    int sum = 0;
    int prime_m;
    cin >> min >> max;

    // 에라토스테네스 체
    vector<bool> prime(max + 1, true);
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i <= max; i++) {
        if (prime[i]) {
            for (int j = i + i; j <= max; j += i) {
                prime[j] = false;
            }
        }
    }
    // min 1개만 구하기
    for (int i = min; i <= max; i++) {
        if (prime[i]) {
            prime_m = i;
            min = i;
            sum += prime_m;

            break;
        }
    }
    // sum 구하기
    for (int i = min + 1; i <= max; i++) {
        if (prime[i]) {
            sum += i;
        }
    }

    if (sum)
        cout << sum << endl << prime_m;
    else
        cout << -1;

    return 0;
}