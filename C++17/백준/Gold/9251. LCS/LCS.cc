#include <iostream>

using namespace std;

int LCS[1001][1001];

void init(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main(){
    init();
    string str1, str2;
    cin >> str1 >> str2;
    int str1_len = str1.length();
    int str2_len = str2.length();
    for(int i = 1; i <= str1_len; i++){
        for(int j = 1; j <= str2_len; j++){
            if(str1[i - 1] == str2[j - 1]){
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            } else {
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
            }
        }
    }
    cout << LCS[str1_len][str2_len];
    
    return 0;
}