#include <bits/stdc++.h>
using namespace std;

int evaluatePostfix(string postfix) {
    stack<int> s;

    for (char c : postfix) {
        if (isdigit(c)) {
            s.push(c - '0'); // Convert char to int
        } else if (c == ' ') {
            continue;
        } else {
            int operand2 = s.top(); s.pop();
            int operand1 = s.top(); s.pop();

            switch (c) {
                case '+': s.push(operand1 + operand2); break;
                case '-': s.push(operand1 - operand2); break;
                case '*': s.push(operand1 * operand2); break;
                case '/': s.push(operand1 / operand2); break;
            }
        }
    }

    return s.top();
}

int main() {
    string postfix = "3 5 2 * +";
    cout << evaluatePostfix(postfix) << endl; // Output: 13
    return 0;
}
