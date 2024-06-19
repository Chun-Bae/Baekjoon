#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, count = 0, eq;
    vector<int> arr;
    vector<int>::iterator it;
    cin >> N; 
    for (int i = 0; i < N; i++){
        int tmp;
        cin>> tmp;
        arr.push_back(tmp);
    }
    
    cin >> eq;

    for (it = arr.begin(); it != arr.end(); it++) 
        if(eq == *it)  count++;
    
    cout << count << endl;
    return 0;
}