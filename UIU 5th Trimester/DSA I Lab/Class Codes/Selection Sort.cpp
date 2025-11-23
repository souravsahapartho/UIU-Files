#include <bits/stdc++.h>

using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the elements
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    int a[n];
    cout << "Enter values: ";
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    cout << "Sorted array: " << endl;
    selectionSort(a,n);
    for(int i=0;i<n;i++) {
        cout <<  a[i] << " ";
    }
    return 0;
}
