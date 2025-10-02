#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;

vector<char> arr;
vector<char> store;
vector<bool> visited;

void bt(int k) {
    if (k == L) {
        int is_consonant = 0;
        int is_vowel = 0;
        for (int i = 0; i < L; i++) {
            switch (store[i]) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    is_vowel++;
                    break;
                default:
                    is_consonant++;
                    break;
            }
        }

        if (is_consonant >= 2 && is_vowel >= 1) {
            for (int i = 0; i < L; i++)
                printf("%c", store[i]);
            printf("\n");
        }

        return;
    }

    for (int i = 0; i < C; i++) {
        if (store[k - 1] > arr[i]) continue;
        if (visited[i] == false) {
            store[k] = arr[i];
            visited[i] = true;
            bt(k + 1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> L >> C;
    arr.resize(C);
    store.resize(L);
    visited.resize(L, false);
    for (int i = 0; i < C; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    bt(0);
    return 0;
}

// 최소 1개 모음
// 최소 2개 자음
// 오름차순이 가능성큼 -> 오름차순 조합구하기
