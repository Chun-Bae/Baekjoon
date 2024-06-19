#include <iostream>
#include <vector>

using namespace std;

int main(){
    string str;
    vector<int> alphabet(26,0);
    cin >>str;
    for(auto& s : str){
        alphabet[s-97]++;
    }
    for(int i = 0; i<26; i++){
        cout << alphabet[i] << " ";
    }
    return 0;
}