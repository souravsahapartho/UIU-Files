
#include<iostream>
using namespace std;
int main()
{
    int n,s;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];

    }
    cin>>s;
    bool found=false;
    for(int i=0; i<n; i++)
    {
        if(a[i]==s)
        {
            cout<<i<<endl;
            found=true;
        }
    }
    if(!found){
        cout<<-1<<endl;
    }



}
