#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int main() {
    init();
    int N;
    cin >> N;
    cin.ignore();

    while (N--) {
        vector<string> words;
        string str, word;
        getline(cin, str);
        stringstream sstream(str);
        while (getline(sstream, word, ' ')) words.push_back(word);

        int size = words.size();
        int mod = words.size();
        int i = 2;
        while (size--) {
            cout << words[i] << " ";
            i++;
            i %= mod;
        }
        cout << '\n';
    }
    return 0;
}