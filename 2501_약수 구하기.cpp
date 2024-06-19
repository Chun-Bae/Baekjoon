#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> divisor;

    for(int i = 1; i<=N; i++){
        if(N%i == 0){
            divisor.push_back(i);
        }
    }
    if(divisor.size())
        cout<<divisor[K-1];
    else
        cout<<0;
    return 0;
}