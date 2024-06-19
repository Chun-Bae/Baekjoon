#include <iostream>

using namespace std;

int main() {
    long long n, sum, tmp;
    int digit = 0;
    bool not_search = true;
    cin >> n;
    tmp = n;
    while (tmp) {
        sum += (tmp % 10);
        tmp = tmp / 10;
        digit++;
    }
    for (long long i = n - digit * 9; i < n; i++) {
        tmp = i;
        sum = 0;
        sum += tmp;
        while (tmp) {
            sum += (tmp % 10);
            tmp = tmp / 10;
        }
        if (sum == n) {
            cout << i << endl;
            not_search = false;
            break;
        }
    }
    if(not_search) cout<<0<<endl;
    return 0;
}