
#include <iostream>
#include <stack>
#include <string>

using namespace std;

void init() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
}

int getPrecedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '(':
            return 0;
        default:
            return -1;
    }
}

string infixToPostfix(const string &expression) {
    stack<char> operators;
    string output;

    for (char token : expression) {
        if (isalpha(token)) {
            output += token;
        } else if (token == '(') {
            operators.push(token);
        } else if (token == ')') {
            while (!operators.empty() && operators.top() != '(') {
                output += operators.top();
                operators.pop();
            }
            operators.pop();
        } else {
            while (!operators.empty() && getPrecedence(operators.top()) >= getPrecedence(token)) {
                output += operators.top();
                operators.pop();
            }
            operators.push(token);
        }
    }

    while (!operators.empty()) {
        output += operators.top();
        operators.pop();
    }

    return output;
}

int main() {
    string expression;
    cin >> expression;

    string postfixExpression = infixToPostfix(expression);
    cout << postfixExpression << endl;

    return 0;
}

// A+B*C-D/E
// 0.
// output = ""
// stack = []
// 1. token = A
// output = "A"
// stack = []
// 2. token = +
// output = "A"
// stack = ["+"]
// 3. token = B
// output = "AB"
// stack = ["+"]
// 4. token = *
// output = "AB"
// stack = ["+", "*"]
// 5. token = C
// output = "ABC"
// stack = ["+", "*"]
// 6. token = -
// output = "ABC*+" (낮은 우선순위이므로  stack에 있는 연산자를 모두 pop하고 현재 연산자를 push)  
// stack = ["-"]  
// 7. token = D
// output = "ABC*+D"
// stack = ["-"]
// 8. token = /
// output = "ABC*+D"
// stack = ["-", "/"]
// 9. token = E
// output = "ABC*+DE"
// stack = ["-", "/"]
// 10. stack에 남아있는 연산자를 모두 pop하여 output에 추가
// output = "ABC*+DE/-"
// stack = []

// A+B*(C-D)/E
// 0.
// output = ""
// stack = []
// 1. token = A
// output = "A"
// stack = []
// 2. token = +
// output = "A"
// stack = ["+"]
// 3. token = B
// output = "AB"
// stack = ["+"]
// 4. token = *
// output = "AB"
// stack = ["+", "*"]
// 5. token = (
// output = "AB"
// stack = ["+", "*", "("]
// 6. token = C
// output = "ABC"
// stack = ["+", "*", "("]
// 7. token = -
// output = "ABC" 
// stack = ["+", "*" , "(" , "-"]
// 8. token = D
// output = "ABCD"
// stack = ["+", "*" , "(" , "-"]
// 9. token = )
// output = "ABCD-" ( '(' 이후의 연산자를 모두 pop하여 output에 추가)
// stack = ["+", "*"]
// 10. token = /
// output = "ABCD-*"
// stack = ["+", "/"]
// 11. token = E
// output = "ABCD-*E"
// stack = ["+", "/"]
// 12. stack에 남아있는 연산자를 모두 pop하여 output에 추가
// output = "ABCD-*E/+"
// stack = []