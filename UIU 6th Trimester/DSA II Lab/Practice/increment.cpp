#include <bits/stdc++.h>
using namespace std;

void increment(int &x)
{
    x++;
}

void Max(int a, int b, int &m)
{
    if (a > b)
    {
        m = a;
    }
    else
    {
        m = b;
    }
}

int main()
{
    int y = 10;
    cout << "Befor Increment: " << y << endl;
    increment(y);
    cout << "After increment: " << y << endl;
    int a = 3, b = 7, m;
    Max(a, b, m);
    cout << "Maximum: " << m << endl;
}