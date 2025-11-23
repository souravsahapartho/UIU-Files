
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


int get_middle(Node * head)
{
    if(head==NULL)
    {
        return -1;
    }


    Node*slow=head;
    Node*fast=head;

    while(fast!=NULL && fast->next!=NULL)
    {
        if(fast->next->next==NULL)
        {
            break;
        }
        slow=slow->next;
        fast=fast->next->next;

    }

    return slow->val;
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

    cout<<"Middle Node: "<<get_middle(head)<<endl;

    return 0;



}
