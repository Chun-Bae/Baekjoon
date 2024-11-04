#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vec1;
typedef vector<vec1> vec2;
typedef vector<vec2> vec3;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}
struct Room {
    int type;
    int atk;
    int hp;
};

bool canSurvive(ll HMaxHP, ll HATK, const vector<Room>& rooms) {
    ll HCurHP = HMaxHP;

    for (const auto& room : rooms) {
        if (room.type == 1) {
            ll roundsToKillMonster = (room.hp + HATK - 1) / HATK;
            ll roundsToDie = (HCurHP + room.atk - 1) / room.atk;

            if (roundsToDie < roundsToKillMonster) return false;
            HCurHP -= room.atk * (roundsToKillMonster - 1);
        } else {
            HATK += room.atk;
            HCurHP = min(HMaxHP, HCurHP + room.hp);
        }
    }
    return true;
}

int main() {
    init();
    int N;
    ll HATK;
    cin >> N >> HATK;

    vector<Room> rooms(N);
    for (int i = 0; i < N; i++) {
        cin >> rooms[i].type >> rooms[i].atk >> rooms[i].hp;
    }

    ll left = 1, right = 1e18;
    ll answer = right;

    while (left <= right) {
        ll mid = (left + right) / 2;
        if (canSurvive(mid, HATK, rooms)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer << endl;
    return 0;
}