#include <bits/stdc++.h>
using namespace std;

class ExpressionProcessor
{
public:
    string infixToPostfix(const string &infix)
    {
        stack<char> operators;
        string postfix;
        map<char, int> precedence = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}};

        for (size_t i = 0; i < infix.length(); i++)
        {
            char c = infix[i];
            if (isdigit(c))
            {
                while (i < infix.length() && isdigit(infix[i]))
                {
                    postfix += infix[i++];
                }
                postfix += ' ';
                i--;
            }
            else if (c == '(')
            {
                operators.push(c);
            }
            else if (c == ')')
            {
                while (!operators.empty() && operators.top() != '(')
                {
                    postfix += operators.top();
                    postfix += ' ';
                    operators.pop();
                }
                operators.pop();
            }
            else if (precedence.count(c))
            {
                while (!operators.empty() && precedence[operators.top()] >= precedence[c])
                {
                    postfix += operators.top();
                    postfix += ' ';
                    operators.pop();
                }
                operators.push(c);
            }
        }

        while (!operators.empty())
        {
            postfix += operators.top();
            postfix += ' ';
            operators.pop();
        }

        return postfix;
    }

    int evaluatePostfix(const string &postfix)
    {
        stack<int> values;
        istringstream tokens(postfix);
        string token;

        while (tokens >> token)
        {
            if (isdigit(token[0]))
            {
                values.push(stoi(token));
            }
            else
            {
                int b = values.top();
                values.pop();
                int a = values.top();
                values.pop();
                switch (token[0])
                {
                case '+':
                    values.push(a + b);
                    break;
                case '-':
                    values.push(a - b);
                    break;
                case '*':
                    values.push(a * b);
                    break;
                case '/':
                    values.push(a / b);
                    break;
                case '^':
                    values.push(pow(a, b));
                    break;
                }
            }
        }

        return values.top();
    }

    pair<string, int> processExpression(const string &infix)
    {
        string postfix = infixToPostfix(infix);
        int result = evaluatePostfix(postfix);
        return {postfix, result};
    }
};

int main()
{
    string expression = "3 + 5 * 2";
    ExpressionProcessor processor;
    auto [postfix, result] = processor.processExpression(expression);

    cout << "Infix Expression: " << expression << endl;
    cout << "Postfix Expression: " << postfix << endl;
    cout << "Evaluated Result: " << result << endl;

    return 0;
}
