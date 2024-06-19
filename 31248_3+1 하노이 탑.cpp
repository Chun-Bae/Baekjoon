#include <iostream>
#include <vector>

using namespace std;

vector<pair<char, char>> moves;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void move(char from, char to) { moves.emplace_back(from, to); }

void hanoi2(int n, char from, char tmp, char to) {
    if (n == 1) {
        move(from, to);
        return;
    }
    hanoi2(n - 1, from, to, tmp);
    hanoi2(1, from, tmp, to);
    hanoi2(n - 1, tmp, from, to);
}

void hanoi(int n, char from, char tmp1, char tmp2, char to) {
    if (n == 0) return;
    if (n == 1) {
        move(from, to);
    } else if (n == 2) {
        move(from, tmp1);
        move(from, to);
        move(tmp1, to);
        return;
    } else {
        hanoi2(n - 2, from, tmp2, tmp1);
        move(from, tmp2);
        move(from, to);
        move(tmp2, to);
        hanoi(n - 2, tmp1, from, tmp2, to);
    }
}

int main() {
    init();
    int N;
    cin >> N;
    hanoi(N, 'A', 'B', 'C', 'D');
    cout << moves.size() << "\n";
    for (const auto& move : moves) {
        cout << move.first << " " << move.second << "\n";
    }
    return 0;
}
// if (n == 1) {
//     move(from, to);
// } else if (n == 2) {
//     move(from, tmp1);
//     move(from, to);
//     move(tmp1, to);
// } else if (n == 3) {
//     move(from, tmp1);
//     move(from, tmp2);
//     move(from, to);

//     move(tmp2, to);
//     move(tmp1, to);
// } else if (n == 4) {
//     move(from, tmp2);
//     move(from, tmp1);
//     move(tmp2, tmp1);
//     move(from, tmp2);
//     move(from, to);

//     move(tmp2, to);
//     move(tmp1, tmp2);
//     move(tmp1, to);
//     move(tmp1, to);
// } else if (n == 5) {
//     move(from, tmp2);
//     move(from, tmp1);
//     move(tmp2, tmp1);
//     move(from, tmp2);
//     move(tmp1, from);
//     move(tmp1, tmp2);
//     move(from, tmp2);
//     move(from, tmp1);
//     move(from, to);

//     move(tmp1, to);
//     move(tmp2, from);
//     move(tmp2, tmp1);
//     move(tmp2, to);
//     move(tmp1, to);
//     move(from, to);
// }