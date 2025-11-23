#include <bits/stdc++.h>
using namespace std;

void sortStack(stack<int> &s)
{
    stack<int> tempStack;

    while (!s.empty())
    {
        int current = s.top();
        s.pop();

        while (!tempStack.empty() && tempStack.top() > current)
        {
            s.push(tempStack.top());
            tempStack.pop();
        }

        tempStack.push(current);
    }

    while (!tempStack.empty())
    {
        s.push(tempStack.top());
        tempStack.pop();
    }
}

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> s;

    s.push(3);
    s.push(1);
    s.push(2);

    cout << "Original Stack: ";
    printStack(s);

    sortStack(s);

    cout << "Sorted Stack: ";
    printStack(s);

    return 0;
}
