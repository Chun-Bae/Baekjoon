#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string number;
    cin >> number;
    
    sort(number.begin(), number.end(), greater<char>());
    cout << number;
    return 0;
}
