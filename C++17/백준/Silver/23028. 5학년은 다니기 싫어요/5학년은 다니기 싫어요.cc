#include <algorithm>
#include <iostream>
#define MAJOR 66
#define TOTAL 130
#define MAX 6
#define CREDIT 3

using namespace std;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();

    int N, A, B;
    cin >> N >> A >> B;

    int major = MAJOR - A;
    int total = TOTAL - B;

    bool canGradu = false;

    for (int i = N; i < 8; i++) {
        int x, y;
        cin >> x >> y;

        int maxMajorCourses = min(x, MAX);
        int maxNonMajorCourses = min(y, MAX - maxMajorCourses);

        int majorCredit = maxMajorCourses * CREDIT;
        int totalCredit = (maxMajorCourses + maxNonMajorCourses) * CREDIT;

        major -= majorCredit;
        total -= totalCredit;

        if (major <= 0 && total <= 0) {
            canGradu = true;
            break;
        }
    }

    if (canGradu) {
        cout << "Nice" << endl;
    } else {
        cout << "Nae ga wae" << endl;
    }

    return 0;
}
