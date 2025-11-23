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

void rotateleft(Node *&head, int n)
{
    Node *temp = head;
    if (!head || n == 0)
    {
        return;
    }
    int length = 1;
    while (temp->next)
    {
        temp = temp->next;
        length++;
    }

    n = n % length;
    if (n == 0)
    {
        return;
    }
    temp->next = head;

    Node *current = head;
    for (int i = 1; i < n; i++)
    {
        current = current->next;
    }
    Node *newHead = current->next;
    current->next = NULL;
    head = newHead;
}

void printList(Node *head)
{
    Node *temp = head;

    while (temp)
    {
        cout << temp->val << " ";
        if (temp->next)
        {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int n, v;
    cout << "Enter the number of nodes (Enter -1 to stop): ";
    while (true)
    {
        cin >> v;
        if (v == -1)
            break;
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

    cout << "Enter the node to swipe left: ";

    cin >> n;
    rotateleft(head, n);
    cout << "Rotated List: ";

    printList(head);

    return 0;
}