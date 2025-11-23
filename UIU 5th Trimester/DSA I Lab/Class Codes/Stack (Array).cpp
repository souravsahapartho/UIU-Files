#include <bits/stdc++.h>

using namespace std;

#define n 100

int s[n];
int top = -1;

bool isFull() {
    return top == n - 1;
}

bool isEmpty() {
    return top == -1;
}

void push(int data) {
    if (isFull()) {
        cout << "Stack overflow" << endl;
        return;
    }

    s[++top] = data;
}

int pop() {
    if (isEmpty()) {
        cout << "Stack underflow" << endl;
        return -1;
    }

    return s[top--];
}

int peek() {
    if (isEmpty()) {
        cout << "Empty Stack" << endl;
        return -1;
    }
    return s[top];
}

void display() {
    if (isEmpty()) {
        cout << "Empty Stack" << endl;
        return;
    }

    cout << "Stack elements: ";
    for (int i = top; i >= 0; i--) {
        cout << s[i] << " ";
    }
    cout << endl;
}

int main() {
    int option, data;

    while (true) {
        cout << "\n!!!  MENU  !!!\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Quit\n";
        cout << "Select an option: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter data to push: ";
                cin >> data;
                push(data);
                break;
            case 2:
                data = pop();
                if (data != -1) {
                    cout << "Popped element: " << data << endl;
                }
                break;
            case 3:
                data = peek();
                if (data != -1) {
                    cout << "Top element: " << data << endl;
                }
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid option. Please select a valid option." << endl;
        }
    }

    return 0;
}
