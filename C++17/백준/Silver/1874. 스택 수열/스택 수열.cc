#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int n;
    cin >> n;
    vector<int> sequence(n);  // 입력 수열을 저장할 벡터
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    stack<int> s;             // 스택
    vector<char> operations;  // 연산 기록을 저장할 벡터
    int current = 1;          // 현재 스택에 넣어야 할 수

    for (int i = 0; i < n; i++) {
        int target = sequence[i];  // 수열에서 원하는 수

        // 현재 수보다 목표 수가 클 때까지 push
        while (current <= target) {
            s.push(current);
            operations.push_back('+');
            current++;
        }

        // 스택의 최상단이 현재 목표 숫자와 일치할 경우 pop
        if (!s.empty() && s.top() == target) {
            s.pop();
            operations.push_back('-');
        } else {
            cout << "NO\n";
            return 0;
        }
    }
    // 1,2,3,4 넣고
    // 4빼고
    // 3빼고
    // 5,6 넣고
    // 6빼고
    // 7,8 넣고
    // 8빼고
    // 7빼고
    // 5빼고
    // 2빼고
    // 1빼고

    for (char op : operations) {
        cout << op << '\n';
    }

    return 0;
}
