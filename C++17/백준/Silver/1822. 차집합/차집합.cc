#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;


void init(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}


int main() {
    init();
    
    int nA, nB;
    cin >> nA >> nB;

    set<int> setA;
    set<int> setB;
    vector<int> result;

    for (int i = 0; i < nA; ++i) {
        int element;
        cin >> element;
        setA.insert(element);
    }

    for (int i = 0; i < nB; ++i) {
        int element;
        cin >> element;
        setB.insert(element);
    }

    for (int element : setA) {
        if (setB.find(element) == setB.end()) {
            result.push_back(element);
        }
    }

    if (result.empty()) {
        cout << "0\n";
    } else {
        sort(result.begin(), result.end()); 
        cout << result.size() << '\n';
        for (int element : result) {
            cout << element << " ";
        }
        cout << '\n';
    }

    return 0;
}
