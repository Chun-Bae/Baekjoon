#include <iostream>

using namespace std;

int main() {
    int N;
    int V, E;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> V >> E;
        cout << 2 - V + E<<endl;
    }
    return 0;
}