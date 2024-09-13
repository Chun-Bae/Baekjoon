#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vec1;
typedef vector<vec1> vec2;
typedef vector<vec2> vec3;
struct Gate {
    ll flow, cost;
};
void init(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main(){
    init();
    int n;
    cin >> n;
    
    vector<Gate> gates(n);
    for (int i = 0; i < n; ++i) {
        cin >> gates[i].flow >> gates[i].cost;
    }
    
    int m;
    cin >> m;
    
    for (int t = 0; t < m; ++t) {
        ll V, T;
        cin >> V >> T;
        
        ll minCost = -1;
        bool possible = false;
        
        for (int mask = 1; mask < (1 << n); ++mask) {
            ll totalFlow = 0, totalCost = 0;
            
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    totalFlow += gates[i].flow;
                    totalCost += gates[i].cost;
                }
            }
            
            if (totalFlow * T >= V) {
                if (minCost == -1 || totalCost < minCost) {
                    minCost = totalCost;
                }
                possible = true;
            }
        }
        
        cout << "Case " << t + 1 << ": ";
        if (possible) {
            cout << minCost << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}