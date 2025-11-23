#include <bits/stdc++.h>
using namespace std;

class StackUsingTwoQueues
{
private:
    queue<int> q1, q2;

public:
    void push(int x)
    {
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop()
    {
        if (q1.empty())
        {
            throw runtime_error("Stack is empty");
        }
        int topElement = q1.front();
        q1.pop();
        return topElement;
    }

    int peek()
    {
        if (q1.empty())
        {
            throw runtime_error("Stack is empty");
        }
        return q1.front();
    }

    bool isEmpty()
    {
        return q1.empty();
    }
};

int main()
{
    StackUsingTwoQueues stack;

    stack.push(1);
    stack.push(2);

    cout << "Pop: " << stack.pop() << endl;                               // Outputs 2
    cout << "Is Empty: " << (stack.isEmpty() ? "True" : "False") << endl; // Outputs False

    return 0;
}
