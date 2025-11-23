#include <iostream>
#include <stack>
using namespace std;

class MiddleStack
{
    stack<int> mainStack;
    stack<int> auxStack;

public:
    void push(int value)
    {
        mainStack.push(value);
        if (auxStack.empty() || auxStack.size() < (mainStack.size() + 1) / 2)
            auxStack.push(value);
    }

    void pop()
    {
        if (mainStack.empty())
            return;
        if (mainStack.top() == auxStack.top())
            auxStack.pop();
        mainStack.pop();
    }

    int findMiddle()
    {
        if (auxStack.empty())
            return -1;
        return auxStack.top();
    }
};

int main()
{
    MiddleStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout << s.findMiddle() << endl;
    return 0;
}
