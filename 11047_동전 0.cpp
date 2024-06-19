#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N,K,coin,count=0;
    vector<int> coins;
    cin >> N >> K;
    for(int i =0; i<N;i++){
    cin >>coin;
    coins.push_back(coin);    
    }
    int i = N-1;
    while(K){
        if(K/coins[i]) {
            count +=  K/coins[i];
           K -= (K/coins[i]) * coins[i];
        }
        i--;
    }
    cout<<count<<endl;
    return 0;
}