#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> N(11);
    N[0] = 0;
    N[1] = 1;  // | 1 |
    N[2] = 2;  // | 1+1 | 2 |
    N[3] = 4;  // | 1+1+1 | 2+1 | 1+2 | 3 |
    N[4] = 7;  // | 1+1+1+1 | 1+1+2 | 1+2+1 | 2+1+1 | 2+2 | 3+1 | 1+3 |
    /// N[n] = N[n-1] + N[n-2] + N[n-3]
    for (int i = 5; i < 11; i++)
        N[i] = N[i - 1] + N[i - 2] + N[i - 3];

    int T;
    cin >> T;
    while(T--){
        int t;
        cin >> t;
        cout<<N[t]<<endl;
    }

    return 0;
}