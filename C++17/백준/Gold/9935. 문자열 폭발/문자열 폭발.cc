#include <iostream>

using namespace std;

char result[1000001];

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    string str, bomb;
    cin >> str >> bomb;
    int str_len = str.length();
    int bomb_len = bomb.length();
    int result_idx = 0;

    for (int i = 0; i < str_len; i++) {
        // bomb 문자열을 만날 때까지 스택에 있는 값은 dummy.
        result[result_idx++] = str[i];        
        if (result[result_idx - 1] == bomb[bomb_len - 1]) {
            // bomb 문자열보다 짧은 인덱스는 같을 수 없음
            if (result_idx < bomb_len) continue;
            bool flag = true;
            // 만약 만났는데 다르면 다시 인덱스 늘리면서 탐색
            for (int j = 0; j < bomb_len; j++) {
                if (result[result_idx - bomb_len + j] != bomb[j]) {
                    flag = false;
                    break;
                }
            }
            // 만나면 bomb 문자열 길이만큼 인덱스를 줄여줌
            // 후차감을 해주는 이유는 문자열을 없앤 이후 끝에서 역으로 길이만큼 탐색이 더 편해서.
            // 12(123)3 idx=4 -> 123 idx=1,
            // 다음 반복으로부터
            // result[result_idx++]를 통해 idx=2 result[2] = 3이 되면서 바로 제거 가능.
            if (flag) result_idx -= bomb_len;
        }
    }
    if (result_idx == 0)
        cout << "FRULA";
    else {
        for (int i = 0; i < result_idx; i++) cout << result[i];
    }
    return 0;
}