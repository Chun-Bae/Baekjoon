#include <iostream>
#include <vector>

using namespace std;

vector<char> s(50);

int top = -1;

int is_emptty() {
    if (top == -1)
        return true;
    else
        return false;
}
int is_full() {
    if (top == 49)
        return true;
    else
        return false;
}

void push(char n) {
    if (is_full()) return;
    top++;
    s[top] = n;
}

int pop() {
    if (is_emptty()) {
        return -1;
    }
    int item = s[top];
    top--;
    return item;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        char str[51];
        scanf("%s", str);
        int check = 0;
        for (int i = 0; str[i] != NULL; i++) {
            if (str[i] == '(') {
                push(str[i]);
            }
            if (str[i] == ')') {
                check = pop();
                if (check == -1) break;
            }
        }
        if (check == -1)
            printf("NO\n");
        else if (top == -1)
            printf("YES\n");
        else
            printf("NO\n");

        top = -1;
    }

    return 0;
}