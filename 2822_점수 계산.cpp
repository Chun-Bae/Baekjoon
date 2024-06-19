#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<pair<int, int>> v; // 2개짜리, 튜플형태 벡터
    vector<int> idx;
    int sum = 0;

    // 입력
    for (int i = 1; i <= 8; i++){
        int num;
        cin >> num;
        v.push_back(make_pair(num, i));
    }
    // 내림차순 정렬
    sort(v.begin(), v.end(), greater<pair<int, int>>()); 
    for (int i = 0; i < 5; i++){
        sum += v[i].first;
        // 인덱스를 다른 벡터로 넣기
        idx.push_back(v[i].second);
    }
    // 인덱스 오름차순 정렬
    sort(idx.begin(), idx.end());
    
    // 출력
    cout << sum << endl;    
    for (auto &i : idx){
        cout << i << ' ';
    }

    return 0;
}