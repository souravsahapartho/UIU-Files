#include <bits/stdc++.h>
using namespace std;

bool temp;

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++) {
        temp = false;
        for (j = 0; j < n - i -1 ; j++) {
            if (arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                temp = true;
            }
        }
        if (temp == false) break;
    }

}


int main()
{
    int n;
    cout << "Enter value of n: ";
    
    cin >> n;

    int a[n];
    cout << "Enter values: ";
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    cout << "Sorted array: " << endl;
    bubbleSort(a,n);
    for(int i=0;i<n;i++) {
        cout <<  a[i] << " ";
    }
    return 0;
}
