#include <iostream>
#include <vector>

using namespace std;

int main() {
    double W, H, N, result;
    cin >> W >> H >> N;

    if (int(N) % 2 == 0)
        result = H * (N / 2 - 1);
    else
        result = H * (N - 1) * (1 - (N + 1) / (2 * N));

    printf("%.6lf", result);

    return 0;
}
