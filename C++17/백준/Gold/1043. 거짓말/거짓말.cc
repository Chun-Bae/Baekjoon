#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void union_sets(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        parent[b] = a;
    }
}

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}   

int main() {
    init();
    int N, M;
    cin >> N >> M;
    
    parent.resize(N + 1);
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
    }
    
    int num_known_truth;
    cin >> num_known_truth;
    
    vector<int> truth_known(num_known_truth);
    for (int i = 0; i < num_known_truth; ++i) {
        cin >> truth_known[i];
    }
    
    vector<vector<int>> parties(M);
    for (int i = 0; i < M; ++i) {
        int num_people;
        cin >> num_people;
        parties[i].resize(num_people);
        for (int j = 0; j < num_people; ++j) {
            cin >> parties[i][j];
        }
        for (int j = 1; j < num_people; ++j) {
            union_sets(parties[i][0], parties[i][j]);
        }
    }
    
    for (int i = 1; i < num_known_truth; ++i) {
        union_sets(truth_known[0], truth_known[i]);
    }
    
    int truth_leader = num_known_truth > 0 ? find(truth_known[0]) : -1;
    
    int max_lie_parties = 0;
    for (const auto& party : parties) {
        bool can_lie = true;
        for (int person : party) {
            if (truth_leader != -1 && find(person) == truth_leader) {
                can_lie = false;
                break;
            }
        }
        if (can_lie) {
            max_lie_parties++;
        }
    }
    
    cout << max_lie_parties << '\n';
    
    return 0;
}
