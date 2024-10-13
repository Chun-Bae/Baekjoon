#include <algorithm>
#include <iostream>
#include <queue>
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

struct Process {
    int adjusted_priority;
    int id;
    int remaining_time;
    Process(int p, int i, int t) : adjusted_priority(p), id(i), remaining_time(t) {}
    bool operator<(const Process &other) const {
        if (adjusted_priority != other.adjusted_priority)
            return adjusted_priority < other.adjusted_priority;
        else
            return id > other.id;
    }
};

int main() {
    init();
    int T, n;
    cin >> T >> n;

    vector<Process> processes;
    long long total_time = 0;

    for (int i = 0; i < n; ++i) {
        int Ai, Bi, Ci;
        cin >> Ai >> Bi >> Ci;
        processes.emplace_back(Ci, Ai, Bi);
        total_time += Bi;
    }

    T = min((long long)T, total_time);

    priority_queue<Process> pq;
    for (const auto &p : processes) {
        pq.push(p);
    }

    for (int time = 1; time <= T; ++time) {
        Process curr = pq.top();
        pq.pop();

        cout << curr.id << '\n';

        curr.remaining_time -= 1;
        curr.adjusted_priority -= 1;

        if (curr.remaining_time > 0) {
            pq.push(curr);
        }
    }

    return 0;
}