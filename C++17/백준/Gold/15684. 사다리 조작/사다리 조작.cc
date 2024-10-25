#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vec1;
typedef vector<vec1> vec2;
typedef vector<vec2> vec3;

void init(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}


int N, M, H;
bool ladder[31][11];
int result = 4; 

bool check() {
    for (int i = 1; i <= N; i++) {
        int position = i;
        for (int j = 1; j <= H; j++) {
            if (ladder[j][position]) position++;
            else if (ladder[j][position - 1]) position--;
        }
        if (position != i) return false;
    }
    return true;
}

void dfs(int count, int x, int y) {
    if (count >= result) return; 
    if (check()) { 
        result = count;
        return;
    }
    if (count == 3) return; 

    for (int i = x; i <= H; i++) {
        for (int j = (i == x ? y : 1); j < N; j++) {
            if (!ladder[i][j] && !ladder[i][j - 1] && !ladder[i][j + 1]) { 
                ladder[i][j] = true;
                dfs(count + 1, i, j + 2);
                ladder[i][j] = false; 
            }
        }
    }
}

int main() {
    init();
    cin >> N >> M >> H;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        ladder[a][b] = true;
    }

    dfs(0, 1, 1);

    if (result > 3) result = -1;
    cout << result << '\n';

    return 0;
}
