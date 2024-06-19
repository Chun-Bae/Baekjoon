#include <iostream>

using namespace std;

int main() {
    int N, p;
    int price, max;
    string name, max_people;
    cin >> N;
    for (int i = 0; i < N; i++) {
        max = 0;
        cin >> p;
        for (int j = 0; j < p; j++) {
            cin >> price >> name;
            if (price > max) {
                max = price;
                max_people = name;
            }
        }
        cout<<max_people<<endl;
    }
    return 0;
}