#include <iostream>
#include <string>

using namespace std;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    string S;
    cin >> S;
    // ()(()에서 하나씩 지울 때
    // )(() -> 올바르지 않음
    // ((() -> 올바르지 않음
    // ()() -> 올바름
    // ()() -> 올바름
    // ()(( -> 올바르지 않음
    int leftCnt = 0, rightCnt = 0;
    int sum = 0, valid = 0;

    for (char c : S) {
        if (c == '(') {
            leftCnt++;
            sum++;
        } else if (c == ')') {
            rightCnt++;
            sum--;
        }

        if (sum < 0) {
            // 우 괄호가 더 많음
            valid = rightCnt;
            break;
        }

        if (sum == 0) {
            // 괄호가 완성됌을 의미
            // 즉, 완성된 괄호는 세워봤자 의미가 없음
            // 완성된 괄호는 지우지 않아도 됌
            // 이는 지웠을 때 올바른 괄호열이 되는 문자가 적어도 하나있기 때문에 가능
            leftCnt = 0;
        }
    }

    if (sum >= 0) {
        valid = leftCnt;
    }

    cout << valid << '\n';
    return 0;
}