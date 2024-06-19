#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int C, N;
    multiset<int> chicken;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> cow;
    cin >> C >> N;

    while (C--) {
        int n;
        cin >> n;
        chicken.insert(n);
    }
    while (N--) {
        int a, b;
        cin >> a >> b;
        cow.push({b, a});
    }
    int cnt = 0;
    
    while (!cow.empty()) {
        int start = cow.top().second;
        int end = cow.top().first;
        auto iter = chicken.lower_bound(start);
        if (iter != chicken.end() && (*iter) <= end) { // end - iter가 가장 짧은 원소
            //cout<<"end:"<<end<<" iter: "<<*iter<<endl;
            cnt++;
            chicken.erase(iter);
        }
        cow.pop();
    }

    cout << cnt;

    return 0;
}