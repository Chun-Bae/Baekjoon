#include <iostream>
using namespace std;

int main() {
    int a, b;
    int sum = 0;
    int first = 0;
    cin >> a >> b;
    for (int i = a; i <= b; i++) {
        for (int j = 1; j <= i; j++) {
            if (i == j * j) {
                if(!first){
                    first = i;
                }
                sum += i;
            }
        }
    }
    
    if (sum)
        cout << sum<<endl<<first;

    else
        cout << -1;

    return 0;
}