#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* link;
};

Node* top = nullptr;

void push(int data) {
    Node* newNode = new Node;
    if (!newNode) {
        cerr << "Stack Overflow" << endl;
        exit(1);
    }

    newNode->data = data;
    newNode->link = top;
    top = newNode;
}

int pop() {
    if (!top) {
        cerr << "Stack Underflow" << endl;
        exit(1);
    }

    int data = top->data;
    Node* temp = top;
    top = top->link;
    delete temp;
    return data;
}

int peek() {
    if (!top) {
        cerr << "Stack is empty" << endl;
        exit(1);
    }
    return top->data;
}

bool isEmpty() {
    return top == nullptr;
}

void display() {
    Node* temp = top;
    cout << "The stack elements are: ";
    while (temp) {
        cout << temp->data << " ";
        temp = temp->link;
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
