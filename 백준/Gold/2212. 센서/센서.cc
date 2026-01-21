#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int N, K;
vector<int> sensors;
vector<int> interval;

void input();
void exception_case();
void sorting(vector<int>& vec);
void get_interval();
void del_largest_interval();
int sum_remainder_interval();
void print_vector(vector<int>& vec);

int main() {
    input();
    exception_case();
    sorting(sensors);
    get_interval();
    sorting(interval);
    del_largest_interval();
    cout << sum_remainder_interval();
    return 0;
}

void exception_case() {
    // 센서보다 집중국이 더 많으면 거리는 무조건 0
    if (N <= K) {
        cout << 0;
        exit(0);
    }
}

void input() {
    cin >> N;
    cin >> K;
    sensors.assign(N, 0);
    interval.assign(N - 1, 0);
    for (int i = 0; i < N; i++) {
        cin >> sensors[i];
    }
}

void sorting(vector<int>& vec) {
    sort(vec.begin(), vec.end());
    // print_vector(vec);
}

void get_interval() {
    for (int i = 0; i < N - 1; i++) {
        interval[i] = sensors[i + 1] - sensors[i];
    }
    // print_vector(interval);
}

void del_largest_interval() {
    for (int i = 0; i < K - 1; i++) {
        interval.pop_back();
    }
    // print_vector(interval);
}

int sum_remainder_interval() {
    return accumulate(interval.begin(), interval.end(), 0);
}

void print_vector(vector<int>& vec) {
    printf("=====\n");
    for (auto v : vec) {
        printf("%d ", v);
    }
    printf("\n=====\n");
}
