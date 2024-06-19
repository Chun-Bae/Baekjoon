#include <iostream>

using namespace std;

int main() {
    int date;
    int car_num;
    int violation = 0;
    cin >> date;
    for (int i = 0; i < 5; i++) {
        cin >> car_num;
        if (car_num == date) violation++;
    }
    cout<<violation;
    return 0;
}