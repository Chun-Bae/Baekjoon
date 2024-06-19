#include <iostream>

using namespace std;

int main(){
    string str;
    int count = 0;
    cin>>str;
    for(auto& s : str){
        cout<<s;
        count++;
        if(count >= 10){
            count %= 10;
            cout<<"\n";
        }
    }
    return 0;
}