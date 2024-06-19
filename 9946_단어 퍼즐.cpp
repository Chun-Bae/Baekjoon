#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string s1, s2;
    for(int i = 1; ;i++){
        cin >> s1 >> s2;
        if (s1 == "END" && s2 == "END") break;
        sort(s1.begin(),s1.end(),less<char>());
        sort(s2.begin(),s2.end(),less<char>());
        if(s1 == s2) cout<< "Case "<<i<<": same"<<endl;
        else cout<< "Case "<<i<<": different"<<endl;

    }
    return 0;
}