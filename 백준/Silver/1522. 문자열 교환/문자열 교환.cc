#include <iostream>

using namespace std;

int main() {
    // string str = "aaaa";
    string str;
    cin>>str;
    int a_cnt=0;
    int len=0;
    int max_a=0;
    for (auto s : str) {
        if (s=='a') a_cnt++;
        len++;
    }
    for (int i=0; i<len; i++) {
        int cnt=0;
        for (int j=i; j<i+a_cnt; j++) {
            int idx = j%len;
            // cout<< str[idx];
            if (str[idx]=='a') cnt++;
            if (max_a<cnt) max_a=cnt;
        }
        // cout<<endl;
    }
    // cout<<a_cnt<<endl;
    // cout<<max_a<<endl;
    cout<<a_cnt-max_a;

    return 0;
}