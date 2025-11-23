#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->next = next;
        this->prev = prev;
    }
};

void Reverse(Node *tail)
{
    Node *temp = tail;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->prev;
    }
}

int main()
{
    int n, v;
    cout << "Enter the number of elements in the list: ";
    cin >> n;
    cout << "Enter the data for node 1: ";
    cin >> v;
    Node *head = new Node(v);
    Node *current = head;
    for (int i = 2; i <= n; i++)

    {
        cout << "Enter the data for the node: ";
        cin >> v;
        Node *newNode = new Node(v);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }
    Node *tail = current;
    cout << "Reversed List: ";
    Reverse(tail);
    cout << endl;
    return 0;
}