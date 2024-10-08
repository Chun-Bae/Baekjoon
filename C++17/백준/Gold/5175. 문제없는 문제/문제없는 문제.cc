#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vec1;
typedef vector<vec1> vec2;
typedef vector<vec2> vec3;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}
void solve(int test_case) {
    int M, N;
    cin >> M >> N;
    cin.ignore();

    vec1 problems(N);

    for (int i = 0; i < N; i++) {
        string line;
        getline(cin, line); 
        stringstream ss(line);
        int alg;
        int bitmask = 0;
        while (ss >> alg) {
            bitmask |= (1 << (alg - 1));  
        }
        problems[i] = bitmask;
    }

    int target = (1 << M) - 1;  

    vec1 best_set;

    for (int mask = 1; mask < (1 << N); mask++) {
        int combined = 0;
        vec1 selected_problems;

        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) {
                combined |= problems[i];
                selected_problems.push_back(i);
            }
        }

        if (combined == target) {
            if (best_set.empty() || selected_problems.size() < best_set.size() || (selected_problems.size() == best_set.size() && selected_problems < best_set)) {
                best_set = selected_problems;
            }
        }
    }

    cout << "Data Set " << test_case << ":";
    for (int i : best_set) {
        cout << " " << char('A' + i);
    }
    cout << endl;
}

int main() {
    init();
    int K;
    cin >> K;
    for (int test_case = 1; test_case <= K; test_case++) {
        solve(test_case);
        cout << endl;
    }
    return 0;
}