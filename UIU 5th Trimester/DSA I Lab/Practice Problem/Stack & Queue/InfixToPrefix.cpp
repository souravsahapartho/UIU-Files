#include <bits/stdc++.h>
using namespace std;

class ExpressionProcessor
{
public:
    string infixToPrefix(const string &infix)
    {
        string reversedInfix, prefix;
        stack<char> operators;
        map<char, int> precedence = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}};

        for (int i = infix.size() - 1; i >= 0; i--)
        {
            char c = infix[i];
            if (c == ')')
            {
                reversedInfix += '(';
            }
            else if (c == '(')
            {
                reversedInfix += ')';
            }
            else
            {
                reversedInfix += c;
            }
        }

        for (char c : reversedInfix)
        {
            if (isdigit(c))
            {
                prefix += c;
            }
            else if (c == '(')
            {
                operators.push(c);
            }
            else if (c == ')')
            {
                while (!operators.empty() && operators.top() != '(')
                {
                    prefix += operators.top();
                    operators.pop();
                }
                operators.pop();
            }
            else
            {
                while (!operators.empty() && precedence[operators.top()] > precedence[c])
                {
                    prefix += operators.top();
                    operators.pop();
                }
                operators.push(c);
            }
        }

        while (!operators.empty())
        {
            prefix += operators.top();
            operators.pop();
        }

        reverse(prefix.begin(), prefix.end());
        return prefix;
    }
};

int main()
{
    string expression = "3 + 5 * 2";
    ExpressionProcessor processor;
    string prefix = processor.infixToPrefix(expression);

    cout << "Infix Expression: " << expression << endl;
    cout << "Prefix Expression: " << prefix << endl;

    return 0;
}
