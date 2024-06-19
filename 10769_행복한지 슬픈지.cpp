#include <iostream>

using namespace std;

int main() {
    string feel;
    string happy = ":-)";
    string sad = ":-(";
    int h_cnt = 0;
    int s_cnt = 0;
    getline(cin, feel);

    size_t pos = feel.find(happy);
    while (pos != string::npos) {
        h_cnt++;
        pos = feel.find(happy, pos + happy.length());
    }

    pos = feel.find(sad);
    while (pos != string::npos) {
        s_cnt++;
        pos = feel.find(sad, pos + sad.length());
    }

    if (h_cnt > s_cnt)
        cout << "happy" << '\n';
    else if (h_cnt < s_cnt)
        cout << "sad" << '\n';
    else if (h_cnt == 0 && s_cnt == 0)
        cout << "none" << '\n';
    else
        cout << "unsure" << '\n';
    return 0;
}