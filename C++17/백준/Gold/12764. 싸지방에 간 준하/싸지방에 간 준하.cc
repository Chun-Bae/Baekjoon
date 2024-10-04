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
struct Person {
    int start, end, index;
};

bool comparePersons(const Person& a, const Person& b) { return a.start < b.start; }

int main() {
    init();
    int N;
    cin >> N;

    vector<Person> people(N);
    for (int i = 0; i < N; ++i) {
        cin >> people[i].start >> people[i].end;
        people[i].index = i;
    }
    sort(people.begin(), people.end(), comparePersons);

    priority_queue<int, vec1, greater<int>> available_seats;
    int seat_count = 0;
    vec1 seat_usage_counts;
    vec1 seat_assigned(N);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupied_seats;

    for (int i = 0; i < N; ++i) {
        int start = people[i].start;
        int end = people[i].end;

        while (!occupied_seats.empty() && occupied_seats.top().first <= start) {
            int seat_num = occupied_seats.top().second;
            occupied_seats.pop();
            available_seats.push(seat_num);
        }

        int seat_num;
        if (available_seats.empty()) {
            seat_num = ++seat_count;
            seat_usage_counts.push_back(1);
        } else {
            seat_num = available_seats.top();
            available_seats.pop();
            seat_usage_counts[seat_num - 1]++;
        }

        seat_assigned[people[i].index] = seat_num;
        occupied_seats.push({end, seat_num});
    }

    cout << seat_count << '\n';
    for (int i = 0; i < seat_count; ++i) cout << seat_usage_counts[i] << ' ';

    return 0;
}