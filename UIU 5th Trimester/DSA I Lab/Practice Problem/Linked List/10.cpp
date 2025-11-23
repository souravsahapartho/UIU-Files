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

void getLoop(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            Node *fast1 = head;
            while (fast1 != slow)
            {
                fast1 = fast1->next;
                slow = slow->next;
            }
            cout << "Loop detected at node with value: " << fast1->val << endl;
            return;
        }
    }
    cout << "No loop detected" << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int v;

    cout << "Enter the nodes (Enter -1 to stop): ";

    while (true)
    {
        cin >> v;
        if (v == -1)
        {
            break;
        }
        else
        {
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
    }
    if (head != NULL && head->next != NULL)
    {
        tail->next = head->next;
    }
    getLoop(head);

    return 0;
}