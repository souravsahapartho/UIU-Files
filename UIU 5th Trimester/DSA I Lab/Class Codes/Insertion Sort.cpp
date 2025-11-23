#include <bits/stdc++.h>

using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
    insertionSort(a,n);
    for(int i=0;i<n;i++) {
        cout <<  a[i] << " ";
    }
    return 0;
}
