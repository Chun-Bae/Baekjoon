#include <iostream>

using namespace std;

int main() {
    int N, ans;
    int sum = 0, count = 0;
    cin>>N;
    for (int i = 0; i < N; i++) {
        cin>> ans;
        if (ans) count++;
        else count = 0;
        sum += count;
    }
    cout<<sum;
    return 0;
}