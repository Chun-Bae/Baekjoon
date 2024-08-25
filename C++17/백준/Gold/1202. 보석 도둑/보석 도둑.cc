#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
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

struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    }
};

int main() {
    init();

    int N, K;
    cin >> N >> K;

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> jewel;
    for (int i = 0; i < N; i++) {
        int weight, price;
        cin >> weight >> price;
        jewel.push({price, weight});
    }

    multiset<int> bags;
    for (int i = 0; i < K; i++) {
        int capacity;
        cin >> capacity;
        bags.insert(capacity);
    }

    ll total = 0;
    while (!jewel.empty()) {
        int price = jewel.top().first;
        int weight = jewel.top().second;
        jewel.pop();

        auto it = bags.lower_bound(weight);
        
        if (it != bags.end()) {
            total += price;
            bags.erase(it);
        }
    }

    cout << total << "\n";

    return 0;
}