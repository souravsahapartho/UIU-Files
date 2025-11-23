#include<iostream>
#include<stack>
using namespace std;

void reverseword(string str)
{
    stack<char>st;

    for(int i=0; i<str.length();  i++)
    {
        if(str[i]!=' ')
        {
            st.push(str[i]);
        }
        else
        {
            while(!st.empty())
            {
                cout<<st.top();
                st.pop();
            }
            cout<<" ";
        }
    }

    while(!st.empty())
    {
        cout<<st.top();
        st.pop();
    }

    cout<<endl;
}

int main
(
)
{
    string input;
    cout<<"Enter a sentence: ";
    getline(cin,input);
    reverseword(input);

}
