#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> pibonacci;
    int N;

    pibonacci.push_back(0);
    pibonacci.push_back(1);

    cin >> N;
    for (int i = 2; i <= N; i++) 
        pibonacci.push_back(pibonacci[i - 1] + pibonacci[i - 2]);
    cout << pibonacci[N];

    return 0;
}