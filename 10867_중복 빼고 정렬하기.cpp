#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> num;
    int T, N;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        num.push_back(N);
    }
    sort(num.begin(),num.end(),less<int>());
    num.erase(unique(num.begin(), num.end()), num.end());
    for (int i = 0; i < num.size(); i++) {
        cout<<num[i]<<" ";
    }
    return 0;
}