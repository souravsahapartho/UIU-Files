#include <iostream>
#include <queue>
using namespace std;

void reverseQueue(queue<int> &q)
{
    if (q.empty())
        return;
    int frontElem = q.front();
    q.pop();
    reverseQueue(q);
    q.push(frontElem);
}

int main()
{
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);

    reverseQueue(q);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
