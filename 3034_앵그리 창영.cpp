#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int N, W, H, len;
    cin >> N >> W >> H;
    double hypotenuse = sqrt(W * W + H * H);
    
    for (int i = 0; i < N; i++) {
        cin >> len;
        hypotenuse >= len ? cout << "DA" : cout << "NE";
        cout << endl;
    }
    return 0;
}