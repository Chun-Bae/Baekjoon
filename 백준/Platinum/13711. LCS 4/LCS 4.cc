#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N + 1);
    vector<int> B(N + 1);
    vector<int> pos(N + 1);
    vector<int> seq(N);

    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= N; i++) cin >> B[i];
    for (int i = 1; i <= N; i++) pos[A[i]] = i;
    for (int i = 1; i <= N; i++) seq[i - 1] = pos[B[i]];

    // printf("A: ");
    // for (int i = 1; i <= N; i++) {
    //     cout << A[i] << " ";
    // }
    // cout << endl;

    // printf("B: ");

    // for (int i = 1; i <= N; i++) {
    //     cout << B[i] << " ";
    // }
    // cout << endl;
    // cout<< "A의 값이랑 인덱스랑 바꾼거"<<endl;
    // for (int i = 1; i <= N; i++) {
    //     printf("pos[%d]: %d\n", A[i], i);
    // }
    // cout<< "B에들어간 숫자 값이 A의 어떤 인덱스인지"<<endl;
    // for (int i = 1; i <= N; i++) {
    //     printf("seq[%d]: %d\n", i-1, pos[B[i]]);
    // }
    vector<int> lis;
    lis.reserve(N);
    for (int x : seq) {
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if (it == lis.end())
            lis.push_back(x);
        else
            *it = x;
    }
    // for (int i = 0; i < N; i++) {
    //     cout << lis[i] << " ";
    // }
    // cout << endl;

    cout << lis.size() << '\n';

    return 0;
}