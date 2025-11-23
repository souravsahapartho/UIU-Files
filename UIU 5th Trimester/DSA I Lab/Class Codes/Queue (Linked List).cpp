#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front=nullptr;
Node* rear=nullptr;


bool isEmpty() {
    return front == nullptr;
}

void enqueue(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = nullptr;

    if (isEmpty()) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue underflow" << endl;
    } else {
        Node* temp = front;
        cout << "Dequeued: " << front->data << endl;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

void printFrontAndRear() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Front element: " << front->data << endl;
        cout << "Rear element: " << rear->data << endl;
    }
}

int main() {
    int option, data;

    while (true) {
        cout << "\n!!!  MENU  !!!\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Print Front and Rear\n";
        cout << "5. Quit\n";
        cout << "Select an option: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter data to enqueue: ";
                cin >> data;
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printFrontAndRear();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid option. Please select a valid option." << endl;
        }
    }

    return 0;
}
