#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void Reverse(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Reverse(head->next);
    cout << head->val << " ";
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int n, v;

    cout << "Enter the number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> v;
        Node *newNode = new Node(v);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "Reversed linked list: ";
    Reverse(head);
    cout << endl;

    return 0;
}
