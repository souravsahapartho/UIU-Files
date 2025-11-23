#include <bits/stdc++.h>

using namespace std;

int binarySearch(int a[], int x, int low, int high)
{
    if (high >= low)
    {
        int mid = low + (high - low) / 2;

        if (a[mid] == x)
            return mid;

        if (a[mid] > x)
            return binarySearch(a, x, low, mid - 1);

        return binarySearch(a, x, mid + 1, high);
    }

    return -1;
}

int main()
{
    int n, value;
    cout << "Enter value of n: ";
    cin >> n;

    int a[n];
    cout << "Enter values: ";
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter search value: ";
    cin >> value;

    int result = binarySearch(a, value, 0, n - 1);
    if (result == -1)
        cout << "Not found";
    else
        cout << "Item found at " << result;
}
