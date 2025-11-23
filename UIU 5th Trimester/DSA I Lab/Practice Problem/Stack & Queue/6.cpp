#include <iostream>
using namespace std;

class CircularQueue
{
    int *arr;
    int front, rear, size, capacity;

public:
    CircularQueue(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    ~CircularQueue()
    {
        delete[] arr;
    }

    bool isFull()
    {
        return size == capacity;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is full\n";
            return;
        }

        if (front == -1)
            front = 0; // First insertion
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
        cout << value << " enqueued\n";
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << arr[front] << " dequeued\n";
        front = (front + 1) % capacity;
        size--;
        if (size == 0)
        { // Reset when queue becomes empty
            front = -1;
            rear = -1;
        }
    }

    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }

        int count = size;
        int i = front;
        cout << "Queue elements: ";
        while (count--)
        {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << "\n";
    }
};

int main()
{
    CircularQueue q(3);

    q.enqueue(1);
    q.enqueue(2);
    q.dequeue();
    q.enqueue(3);
    q.dequeue();

    cout << "Is full: " << (q.isFull() ? "True" : "False") << endl;

    q.display();

    return 0;
}
