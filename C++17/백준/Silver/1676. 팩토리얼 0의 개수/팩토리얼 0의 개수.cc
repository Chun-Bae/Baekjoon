#include <iostream>

using namespace std;

typedef long long ll;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int N;
    cin >> N;
    int count = 0;
    
    // 25!은 5가 2개들어감 
    // 따라서 5, 10, 15 ,20는 5가 4개 | 25는 5가 2개들어감
    for (int i = 5; i <= N; i *= 5) {
        count += N / i;
    }
    
    cout << count << '\n';
    return 0;
}
