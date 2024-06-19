#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string str;
    int sum = 0;
    cin >> str;
    vector<string> words;
    stringstream sstream(str);
    string word;

    while (getline(sstream, word, ',')) words.push_back(word);
    for (int i = 0; i < words.size(); i++) sum += stoi(words[i]);
    cout << sum;
    return 0;
}