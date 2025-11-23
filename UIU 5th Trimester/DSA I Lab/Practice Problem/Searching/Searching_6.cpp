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
    bool found=false;
    cin>>s;
    while(l<=r)
    {
        int mid=(l+r)/2;

        if(a[mid]==s)
        {
            cout<<mid<<" ";
            found=true;



            int left=mid-1;
            while(left>=0 && a[left]==s)
            {
                cout<<left<<" ";
                left--;
            }

            int right=mid+1;
            while(right<n && a[right]==s)
            {
                cout<<right<<" ";
                right++;
            }
            break;

        }

        else if(a[mid]<s)
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }

    }


    if(!found)
    {
        cout<<-1<<endl;
    }
}

