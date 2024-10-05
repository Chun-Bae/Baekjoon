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

struct Line {
    int start, end;
};

bool compare(Line a, Line b) {
    if (a.start == b.start) return a.end < b.end;
    return a.start < b.start;
}

int main() {
    init();
    int N;
    cin >> N;

    vector<Line> lines(N);
    for (int i = 0; i < N; i++) cin >> lines[i].start >> lines[i].end;
    sort(lines.begin(), lines.end(), compare);

    ll totalLength = 0;
    int currentStart = lines[0].start;
    int currentEnd = lines[0].end;

    for (int i = 1; i < N; i++) {
        if (lines[i].start <= currentEnd) {
            currentEnd = max(currentEnd, lines[i].end);
        }
        else {
            totalLength += (currentEnd - currentStart);
            currentStart = lines[i].start;
            currentEnd = lines[i].end;
        }
    }

    totalLength += (currentEnd - currentStart);

    cout << totalLength << endl;
    return 0;
}