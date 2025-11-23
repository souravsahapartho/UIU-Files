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
    int l=0;
    int r=n-1;
    int position=n;
    cin>>s;
    while(l<=r)
    {
        int mid=(l+r)/2;

        if(a[mid]==s)
        {
            cout<<mid<<endl;
            return 0;
        }
        else if(a[mid]<s)
        {
            l=mid+1;
        }
        else
        {
            position =mid;
            r=mid-1;
        }

    }

    cout<<l<<endl;

}
