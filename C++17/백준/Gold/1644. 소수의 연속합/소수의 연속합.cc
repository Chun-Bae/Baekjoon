#include <iostream>
#include <vector>

using namespace std;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

vector<int> getPrimes(int N) {
    vector<bool> isPrime(N + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= N; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }
    vector<int> primes;
    for (int i = 2; i <= N; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

int main() {
    init();
    int N;
    cin >> N;

    vector<int> primes = getPrimes(N);
    int count = 0;
    int sum = 0;
    int start = 0;
    int end = 0;

    while (true) {
        if (sum >= N) {
            sum -= primes[start++];
        } else if (end == primes.size()) {
            break;
        } else {
            sum += primes[end++];
        }
        if (sum == N) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
