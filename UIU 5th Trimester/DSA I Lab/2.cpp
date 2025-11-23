#include<iostream>
#include<stack>
using namespace std;

bool isvalid(string s)
{

    stack<char>st;

    for(char ch:s)
    {
        if(ch=='('||ch=='{'||ch=='[')
        {
            st.push(ch);
        }
        else
        {
            if(st.empty())
            {
                return false;
            }



            char top=st.top();
            if((ch==')'&& top=='(') ||
                    (ch=='}'&& top=='{')||(ch==']'&& top=='['))
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }

    }
    return st.empty();
}

int main()
{
    string input;
    cout<<"Enter string: ";
    cin>>input;

    if(isvalid(input))
    {
        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }
}


