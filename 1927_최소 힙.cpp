#include <iostream>
#include <queue>

using namespace std;

void init(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    priority_queue<int, vector<int>,greater<int>> q;
    int N;
    cin >> N;

    while (N--) {
        int x;
        cin >> x;
        if (!q.size() && x == 0) {
            cout<<0<<'\n';
        }
        else if(x==0){
            cout<<q.top()<<'\n';
            q.pop();
        }
        else{
            q.push(x);
        }
    }
    return 0;
}