#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vec1;
typedef vector<vec1> vec2;
typedef vector<vec2> vec3;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int evaluate(string expression) {
    string exp_no_spaces;
    for (char ch : expression) {
        if (ch != ' ') exp_no_spaces += ch;
    }

    int total = 0;
    int num = 0;
    char op = '+';

    for (size_t i = 0; i <= exp_no_spaces.size(); ++i) {
        if (i < exp_no_spaces.size() && isdigit(exp_no_spaces[i])) {
            num = num * 10 + (exp_no_spaces[i] - '0');
        } else {
            if (op == '+') {
                total += num;
            } else if (op == '-') {
                total -= num;
            }
            if (i < exp_no_spaces.size()) {
                op = exp_no_spaces[i];
            }
            num = 0;
        }
    }

    return total;
}
void generateExpressions(int n, string expression, int curr_num, vector<string>& results) {
    if (curr_num == n) {
        if (evaluate(expression) == 0) {
            results.push_back(expression);
        }
        return;
    }

    string next_num = to_string(curr_num + 1);

    generateExpressions(n, expression + " " + next_num, curr_num + 1, results);
    generateExpressions(n, expression + "+" + next_num, curr_num + 1, results);
    generateExpressions(n, expression + "-" + next_num, curr_num + 1, results);
}
int main() {
    init();
    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        int N;
        cin >> N;

        vector<string> results;

        generateExpressions(N, "1", 1, results);

        sort(results.begin(), results.end());

        for (const string& expr : results) {
            cout << expr << '\n';
        }
        cout << '\n';
    }

    return 0;
}
