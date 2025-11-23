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

void rotateleft(Node *&head, int k)
{
    if (!head || k == 0)
        return;

    // Find the length of the list
    Node *temp = head;
    int length = 1;
    while (temp->next)
    {
        temp = temp->next;
        length++;
    }

    // Normalize k to avoid unnecessary rotations
    k = k % length;
    if (k == 0)
    {
        return;
    }

    // Make the list circular
    temp->next = head;

    // Find the (k-1)th node (new tail) and k-th node (new head)
    Node *current = head;
    for (int i = 1; i < k; i++)
    {
        current = current->next;
    }

    // The node after current will be the new head
    Node *newHead = current->next;

    // Break the circle by setting current's next to NULL
    current->next = NULL;

    // Update head to the new head
    head = newHead;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->val;
        if (temp->next)
        {
            cout << "->";
        }
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int val;

    cout << "Enter the values for the linked list (-1 to stop): ";
    while (true)
    {
        cin >> val;
        if (val == -1)
            break;
        Node *newNode = new Node(val);
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

    cout << "Original List: ";
    printList(head);

    int k;
    cout << "Enter the number of positions to rotate left: ";
    cin >> k;

    rotateleft(head, k);

    cout << "Rotated List: ";
    printList(head);

    return 0;
}

