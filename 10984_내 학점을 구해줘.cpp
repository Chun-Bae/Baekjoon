#include <iostream>
#include <vector>

using namespace std;

void func(int K) {
    int a;
    float b;
    int sum_a = 0;
    float sum_b = 0;

    for (int i = 0; i < K; i++) {
        cin >> a >> b;

        sum_a += a;
        sum_b += a * b;
    }
    cout << sum_a << " ";

    cout << fixed;
    cout.precision(1);
    cout << float(sum_b / sum_a) << endl;
}

int main() {
    int N, K;

    cin >> N;
    for(int i =0; i<N; i++){
        cin >> K;
        func(K);
    }

    return 0;
}
