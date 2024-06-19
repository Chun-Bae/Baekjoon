#include <iostream>
#include <vector>

using namespace std;

void input(vector<int>* ab) {
    int k;
    for (int i = 0; i < 10; i++) {
        cin >> k;
        ab->push_back(k);
    }
}

int main() {
    int a_score = 0, b_score = 0;
    int last = 0;
    vector<int> a, b;
    input(&a);
    input(&b);
    
    for (int i = 0; i < 10; i++) {
        if (a[i] - b[i] > 0) {
            a_score += 3;
            last = 'a';
        } else if (a[i] - b[i] < 0) {
            b_score += 3;
            last = 'b';
        } else {
            a_score++;
            b_score++;
        }
    }

    cout << a_score << " " << b_score << '\n';
    (a_score > b_score) ? cout << 'A' : ((a_score < b_score) ? cout << 'B' : (last == 'a' ? cout << 'A' : (last == 'b' ? cout << 'B' : cout << 'D')));

    return 0;
}