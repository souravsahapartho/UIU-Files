#include <bits/stdc++.h>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

string infixToPostfix(string infix) {
    stack<char> operators;
    string postfix = "";

    for (char c : infix) {
        if (isdigit(c)) {
            postfix += c;
        } else if (isspace(c)) {
            continue;
        } else if (isOperator(c)) {
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

int main() {
    string infix = "3 + 5 * 2";
    cout << infixToPostfix(infix) << endl; // Output: 3 5 2 * +
    return 0;
}

