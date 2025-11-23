#include <bits/stdc++.h>

using namespace std;

#define n 100
int Queue[n];
int front = -1, rear = -1;

bool isFull() {
    return rear == n - 1;
}

bool isEmpty() {
    return front == -1 && rear == -1;
}

void enqueue(int x) {
    if (isFull()) {
        cout << "Queue overflow" << endl;
    } else if (isEmpty()) {
        front = rear = 0;
        Queue[rear] = x;
    } else {
        Queue[++rear] = x;
    }
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue underflow" << endl;
    } else if (front == rear) {
        cout << "Dequeued: " << Queue[front] << endl;
        front = rear = -1;
    } else {
        cout << "Dequeued: " << Queue[front++] << endl;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << Queue[i] << " ";
        }
        cout << endl;
    }
}

void printFrontAndRear() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Front element: " << Queue[front] << endl;
        cout << "Rear element: " << Queue[rear] << endl;
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
