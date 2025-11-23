#include <iostream>
#include <stack>
using namespace std;

void printReverse(stack<int> &st)
{
    if (st.empty())
        return;
    int topElem = st.top();
    cout << topElem << " ";
    st.pop();
    printReverse(st);
    st.push(topElem);
}

int main()
{
    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);

    printReverse(st);

    return 0;
}
