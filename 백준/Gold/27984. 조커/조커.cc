#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>
#define POKER 4
using namespace std;

vector<int> S(POKER + 1);
vector<int> R(POKER + 1);

bool is_straight_flush();
bool is_quadruple();
bool is_full_house();
bool is_flush();
bool is_straight();
bool is_triple();
bool is_two_pair();
bool is_pair();

int validation(int i, int j, int f, bool (*func)()) {
    if (func()) {
        printf("%d %d\n", i, j);
        // f는 확인용
        // printf("%d\n", f);
        return 1;
    }
    return 0;
}

int main() {
    for (int i = 0; i < POKER; i++) {
        cin >> S[i];
        cin >> R[i];
    }
    // bool (*funcs[8])();
    vector<bool (*)()> funcs(8);
    funcs[0] = &is_straight_flush;
    funcs[1] = &is_quadruple;
    funcs[2] = &is_full_house;
    funcs[3] = &is_flush;
    funcs[4] = &is_straight;
    funcs[5] = &is_triple;
    funcs[6] = &is_two_pair;
    funcs[7] = &is_pair;

    for (int f = 0; f < 8; f++) {
        for (int i = 0; i < 4; i++) {
            S[4] = i;
            for (int j = 1; j < 14; j++) {
                R[4] = j;

                bool is_existing = 0;
                for (int t = 0; t < 4; t++) {
                    if (S[t] == S[4] && R[t] == R[4]) {
                        is_existing = 1;
                        break;
                    }
                }
                if (is_existing) continue;
                if (validation(i, j, f, funcs[f])) {
                    return 0;
                }
            }
        }
    }

    return 0;
}

bool is_straight_flush() {
    vector<int> copy_R = R;
    sort(copy_R.begin(), copy_R.end());
    int criterion_s = S[0];
    int criterion_r = copy_R[0];

    for (int i = 1; i < POKER + 1; i++) {
        if (criterion_s != S[i])
            return 0;
    }

    for (int i = 1; i < POKER + 1; i++) {
        if ((criterion_r + 1) != copy_R[i])
            return 0;
        criterion_r++;
    }

    return 1;
}

bool is_quadruple() {
    if (R[0] == R[1] &&
        R[1] == R[2] &&
        R[2] == R[3])
        return 1;
    if (R[0] == R[2] &&
        R[2] == R[3] &&
        R[3] == R[4])
        return 1;
    if (R[0] == R[1] &&
        R[1] == R[3] &&
        R[3] == R[4])
        return 1;
    if (R[0] == R[1] &&
        R[1] == R[2] &&
        R[2] == R[4])
        return 1;
    if (R[1] == R[2] &&
        R[2] == R[3] &&
        R[3] == R[4])
        return 1;

    return 0;
}

bool is_full_house() {
    vector<int> copy_R = R;
    sort(copy_R.begin(), copy_R.end());
    // 0 1 2 3 4
    // 0==1 && 3==4
    if (copy_R[0] == copy_R[1]) {
        if (copy_R[3] == copy_R[4]) {
            if (copy_R[2] == copy_R[3] || copy_R[2] == copy_R[1]) {
                return 1;
            }
        }
    }

    return 0;
}

bool is_flush() {
    int criterion_s = S[0];
    for (int i = 1; i < POKER + 1; i++) {
        if (criterion_s != S[i])
            return 0;
    }
    return 1;
}

bool is_straight() {
    vector<int> copy_R = R;
    sort(copy_R.begin(), copy_R.end());
    // 0 1 2 3 4
    int criterion_r = copy_R[0];
    if (criterion_r == 1) {
        if (copy_R[1] == 10 &&
            copy_R[2] == 11 &&
            copy_R[3] == 12 &&
            copy_R[4] == 13) {
            return 1;
        }
    }
    for (int i = 1; i < POKER + 1; i++) {
        if ((criterion_r + 1) != copy_R[i])
            return 0;
        criterion_r++;
    }
    return 1;
}

bool is_triple() {
    for (int i = 0; i < POKER + 1; i++) {
        for (int j = 0; j < POKER + 1; j++) {
            if (j == i) continue;
            for (int k = 0; k < POKER + 1; k++) {
                if (k == j || k == i) continue;
                if (R[i] == R[j] && R[i] == R[k]) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

bool is_two_pair() {
    vector<int> copy_R = R;
    sort(copy_R.begin(), copy_R.end());
    if (copy_R[0] == copy_R[1] && copy_R[2] == copy_R[3])
        return 1;
    if (copy_R[0] == copy_R[1] && copy_R[3] == copy_R[4])
        return 1;
    if (copy_R[1] == copy_R[2] && copy_R[3] == copy_R[4])
        return 1;
    return 0;
}

bool is_pair() {
    for (int i = 0; i < POKER + 1; i++) {
        for (int j = 0; j < POKER + 1; j++) {
            if (j == i) continue;
            if (R[i] == R[j]) {
                return 1;
            }
        }
    }
    return 0;
}