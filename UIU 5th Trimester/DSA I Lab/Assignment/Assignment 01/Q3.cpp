#include <bits/stdc++.h>
using namespace std;

int main()
{
    string ch;
    int frequency[26] = {0};

    cout << "Enter a string: ";
    cin >> ch;

    for (char c : ch)
    {
        if (c >= 'a' && c <= 'z')
        {
            frequency[c - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        cout << char('a' + i) << " : " << frequency[i] << endl;
    }
    return 0;
}