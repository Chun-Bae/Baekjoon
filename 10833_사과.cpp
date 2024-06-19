#include <iostream>

using namespace std;

int main(){
    int N,apple,student;
    int residue_sum = 0;
    cin>>N;

    for(int i= 0 ; i<N;i++){
        cin>>student>>apple;
        residue_sum += apple%student;
    }
    cout<<residue_sum;
    return 0;
}
