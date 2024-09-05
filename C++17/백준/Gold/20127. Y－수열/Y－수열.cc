#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vec1;
typedef vector<vec1> vec2;
typedef vector<vec2> vec3;

void init(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main(){
    init();
    
    int n, a = 0, b = 0;
    cin >> n;
    deque<int> dq(n);
    
    for(auto &i : dq) cin >> i;

    if(n <= 2) { 
        cout << 0; 
        return 0; 
    }

    for(int i = 1; i < n; i++){
        if(dq[i-1] < dq[i]) a++;
        if(dq[i-1] > dq[i]) b++;
    }

    for(int i = 0; i <= n; i++){
        // 증가 또는 감소 수열 i=0일 때도 유효
        if(!a || !b){ 
            cout << i; 
            return 0; 
        }
        if(dq[0] < dq[1]) a--;
        if(dq[0] > dq[1]) b--;
        if(dq.back() < dq[0]) a++;
        if(dq.back() > dq[0]) b++;
        dq.push_back(dq.front());
        dq.pop_front();
    }

    cout << -1;

    return 0;
}
