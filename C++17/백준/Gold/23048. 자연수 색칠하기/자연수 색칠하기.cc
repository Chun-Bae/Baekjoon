#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 500000;

vector<int> colors(MAX_N + 1, 0);
vector<int> is_prime(MAX_N + 1, true);

void sieve_of_eratosthenes(int n) {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int N;
    cin >> N;

    sieve_of_eratosthenes(N);

    int color_count = 1;

    // 소수에 색을 칠하고, 소수가 아닌 숫자에는 다른 색을 칠하기
    for (int i = 2; i <= N; ++i) {
        if (is_prime[i]) {
            ++color_count;
            for (int j = i; j <= N; j += i) {
                if (colors[j] == 0) {
                    colors[j] = color_count;
                }
            }
        }
    }

    // 소수가 아닌 자연수에는 새로운 색 추가
    int non_prime_color = color_count + 1;
    colors[1] = 1;
    for (int i = 2; i <= N; ++i) {
        if (!is_prime[i] && colors[i] == 0) {
            colors[i] = non_prime_color;
        }
    }

    cout << color_count << endl;
    for (int i = 1; i <= N; ++i) {
        cout << colors[i] << ' ';
    }
    cout << endl;

    return 0;
}
