#include <iostream>
#include <vector>

using namespace std;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int t, s, n;
    cin >> t >> s >> n;
    vector<int> flips(n);
    for (int i = 0; i < n; ++i) {
        cin >> flips[i];
    }

    int upSand = 0, downSand = s;
    int currentTime = 0;

    for (int i = 0; i < n; ++i) {
        int flipTime = flips[i];
        int deltaTime = flipTime - currentTime;
        int tmp;
        
        if (i) {
            upSand -= deltaTime;
            if (upSand < 0) upSand = 0;
            downSand += deltaTime;
            if (downSand > s) downSand = s;
        }
        tmp = upSand;
        upSand = downSand;
        downSand = tmp;

        currentTime = flipTime;
    }

    int deltaTime = t - currentTime;
    upSand -= deltaTime;
    if (upSand < 0) upSand = 0;

    cout << upSand << endl;
    return 0;
}