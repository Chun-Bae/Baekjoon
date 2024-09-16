#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;
typedef long long ll;
typedef vector<double> vec1;
typedef vector<vec1> vec2;
typedef vector<vec2> vec3;
const double INF = 1e18;
int n;
vec2 cost;
vec1 u, v;
vector<int> p, way;

void init(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    cin >> n;
    cost.assign(n + 1, vec1(n + 1, 0));
    u.assign(n + 1, 0);
    v.assign(n + 1, 0);
    p.assign(n + 1, 0);
    way.assign(n + 1, 0);

    vec1 P(n), R(n);
    for (int i = 0; i < n; ++i) {
        cin >> P[i] >> R[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cost[i][j] = P[i - 1] * pow(R[i - 1], j - 1);
        }
    }

    for (int i = 1; i <= n; ++i) {
        p[0] = i;
        vec1  minv(n + 1, INF);
        vector<bool> used(n + 1, false);
        int j0 = 0;
        do {
            used[j0] = true;
            int i0 = p[j0], j1;
            double delta = INF;
            for (int j = 1; j <= n; ++j) {
                if (!used[j]) {
                    double cur = cost[i0][j] - u[i0] - v[j];
                    if (cur < minv[j]) {
                        minv[j] = cur;
                        way[j] = j0;
                    }
                    if (minv[j] < delta) {
                        delta = minv[j];
                        j1 = j;
                    }
                }
            }
            for (int j = 0; j <= n; ++j) {
                if (used[j]) {
                    u[p[j]] += delta;
                    v[j] -= delta;
                } else {
                    minv[j] -= delta;
                }
            }
            j0 = j1;
        } while (p[j0] != 0);
        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }

    vector<int> ans(n + 1);
    for (int j = 1; j <= n; ++j) {
        ans[p[j]] = j;
    }
    double total_cost = 0.0;
    for (int i = 1; i <= n; ++i) {
        int t = ans[i] - 1;
        total_cost += P[i - 1] * pow(R[i - 1], t);
    }

    cout << fixed << setprecision(2) << total_cost << endl;

    return 0;
}
