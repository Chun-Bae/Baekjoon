#include <iostream>

using namespace std;

typedef long long ll;

void init(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main(){
    init();
    int N;
    
    cin >> N;
    while(N--){
        int n;
        cin >> n;
        if(n == 1){
            cout << 1 << '\n';

        }
        else if(n==2){
            cout << 2 << '\n';
        }
        else if(n==3){
            cout << 6 << '\n';
        }
        else if(n==4){
            cout << 4 << '\n';
        }
        else{
            cout << 0 << '\n';
        }

    }

    return 
    0;
}