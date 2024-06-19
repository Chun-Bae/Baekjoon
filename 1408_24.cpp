#include <iostream>
#include <vector>
using namespace std;

int time2sec(string str) {
    int sum = 0;
    sum += stoi(str.substr(0, 2)) * 3600; 
    sum += stoi(str.substr(3, 2)) * 60;   
    sum += stoi(str.substr(6, 2));        
    return sum;
}

vector<int> sec2time(int sec) {
    vector<int> time;
    time.push_back(sec / 3600);         
    sec %= 3600;
    time.push_back(sec / 60);           
    sec %= 60;
    time.push_back(sec);           
    return time;
}


void print_time(vector<int> time) {
    for (int i = 0; i < 3; i++) {
        cout.width(2);
        cout.fill('0');
        cout << time.at(i);
        if (i < 2) cout << ":";
    }
}

int main() {
    string a, b;
    vector<int> time;
    int r_time;
    cin >> a >> b;
    r_time = time2sec(b) - time2sec(a);
    if (r_time < 0) {
        r_time += 24 * 3600;
    }
    time = sec2time(r_time);
    print_time(time);   
    return 0;
}