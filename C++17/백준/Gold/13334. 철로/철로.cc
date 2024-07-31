#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Person {
    int start, end;
    Person(int h, int o) {
        start = min(h, o);
        end = max(h, o);
    }
};

bool compare(const Person &a, const Person &b) {
    return a.end < b.end;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    cin >> n;
    vector<Person> people;

    for (int i = 0; i < n; ++i) {
        int h, o;
        cin >> h >> o;
        people.emplace_back(h, o);
    }
    cin >> d;

    sort(people.begin(), people.end(), compare);

    priority_queue<int, vector<int>, greater<int>> pq;
    int maxCount = 0;

    for (const auto &person : people) {
        pq.push(person.start);

        while (!pq.empty() && pq.top() < person.end - d) {
            pq.pop();
        }

        maxCount = max(maxCount, (int)pq.size());
    }

    cout << maxCount << endl;

    return 0;
}
