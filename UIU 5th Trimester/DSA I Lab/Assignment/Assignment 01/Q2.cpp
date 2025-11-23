#include <bits/stdc++.h>
using namespace std;

void mirrorRow(string row, string &mirroredrow)
{
    int n = row.size();
    mirroredrow = row;

    for (int i = 0; i < n / 2; i++)
    {
        swap(mirroredrow[i], mirroredrow[n - i - 1]);
    }
}

int main()
{
    int n;

    cout << "Enter the number of rows: ";
    cin >> n;
    cin.ignore();

    string row[n];
    string mirroredrow[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter row " << i << " : ";
        getline(cin, row[i]);
    }

    for (int i = 0; i < n; i++)
    {
        mirrorRow(row[i], mirroredrow[i]);
    }

    cout << "\nMirrored Rows:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Row " << i << " : " << mirroredrow[i] << endl;
    }
}