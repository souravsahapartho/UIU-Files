#include<iostream>
using namespace std;

class Node
{
public:
    int val;
    Node*next;
    Node(int val)
    {
        this->val=val;
        this->next=NULL;
    }

};

void printList(Node* head)
{
    Node * temp=head;
    while(temp!=NULL)
    {
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout << endl;

}


Node* del_even(Node * head)
{
    while(head!=NULL && head->val%2==0)
    {
        Node*temp=head;
        head=head->next;
        delete temp;
    }


    Node *temp=head;
    while(temp!=NULL && temp->next!=0)
    {
        if(temp->next->val%2==0)
        {

            Node *deleteNode=temp->next;
            temp->next=temp->next->next;
            delete deleteNode;

        }
        else
        {
            temp=temp->next;
        }


    }
    return head;
}
int main()
{
    Node * head= NULL;
    Node * tail=NULL;



    int n,v;
    cout<<"Enter the number of elements: "<<endl;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>v;
        Node * newNode=new Node(v);

        if(head==NULL)
        {
            head=newNode;
            tail=newNode;
        }
        else
        {
            tail->next=newNode;
            tail=newNode;
        }
    }

    cout<<"Original List:"<<" ";
    printList(head);


    head=del_even(head);


    cout<<"NewNode:"<<" ";
    printList(head);

    return 0;

}
