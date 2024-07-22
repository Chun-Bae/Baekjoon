#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

typedef long long ll;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int T;
    cin >> T;
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int m;
    cin >> m;
    vector<int> B(m);
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }
    // 부 배열의 합의 빈도를 저장하는 해시 테이블
    unordered_map<int, int> sumA;
    for (int i = 0; i < n; i++) {
        int current_sum = 0;
        for (int j = i; j < n; j++) {
            current_sum += A[j];
            sumA[current_sum]++;
        }
    }

    ll count = 0;
    // B의 모든 부 배열의 합을 계산하고 sumA에서 T와의 차이를 찾는다.
    for (int i = 0; i < m; i++) {
        int current_sum = 0;
        for (int j = i; j < m; j++) {
            current_sum += B[j];
            int required_sum = T - current_sum;
            if (sumA.find(required_sum) != sumA.end()) {
                // A의 빈도를 더해주면 A에서 경우의 수를 굳이 세지 않아도 된다.
                count += sumA[required_sum];
            }
        }
    }

    cout << count << endl;

    return 0;
}
