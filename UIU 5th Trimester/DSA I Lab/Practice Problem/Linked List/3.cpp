
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


int get_occur(Node * head, int s)
{
    int count=0;
    Node *temp=head;
    while(temp!=NULL)
    {
        if(temp->val==s)
        {
            count++;
        }
        temp=temp->next;
    }
    return count;

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
    int s;
    cout<<"Enter occurrences digit: "<<endl;
    cin>>s;

       cout<<"Occurrences: "<<get_occur(head,s)<<endl;

    return 0;

}
