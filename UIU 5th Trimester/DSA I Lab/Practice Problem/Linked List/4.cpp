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

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        if (temp->next != NULL)
        {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

Node *insertsorted(Node *head, int s)
{
    Node *newNode = new Node(s);

    if (head == NULL || s < head->val)
    {
        newNode->next = head;
        return newNode;
    }

    Node *temp = head;
    while (temp->next != NULL && temp->next->val < s)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int n, v;
    cout << "Enter the number of elements: " << endl;
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

    int s;
    cout << "Enter the digit to insert: ";
    cin >> s;

    cout << "Original List: ";
    printList(head);

    head = insertsorted(head, s);

    cout << "NewNode: ";
    printList(head);

    return 0;
}
