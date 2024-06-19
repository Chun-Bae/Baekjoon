#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, T;
vector<int> a;

//  세미나 수 maxSnum 대해, 모든 세미나를 배정할 수 있는지 확인하는 함수
bool semi(int maxSnum) {
    vector<int> end_time;  // 각 세미나의 종료 시간을 저장하는 벡터
    for (int i = 0; i < N; i++) {
        int day = a[i];
       
        int start = max(1, day - (T - 1));

        if (end_time.size() < maxSnum) {
            end_time.push_back(start + T);
        } else {
            int end_or_day_cmp = max(end_time[end_time.size() - maxSnum], start);  // if가 안될때 이제 end_time 새로 들어온 값이랑 비교해서 넣기,
            // [end_time.size() - maxSnum] = [맨처음 들어온 day 마지막 일자가 들어간 인덱스] end_time.size()는 +1씩 증가

            if (end_or_day_cmp > day) return false;  // 여기서 end_new_cmp는 end값을 의미, 즉 새로들어온 day값이 종료된 값보다 작으면 세미나 수를 하나 늘려야 해서 안됌.
            end_time.push_back(end_or_day_cmp + T);  // 새로 들어온 값이 채택되면 종료 시간을 업데이트하여 추가
        }
    }
    return true;
}

int binary_tree(int left, int right) {
    while (left < right) {
        int mid = (left + right) / 2;
        if (semi(mid))
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int main() {
    cin >> N >> T;
    a.resize(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    sort(a.begin(), a.end());
    cout << binary_tree(1, N + 1);
    return 0;
}