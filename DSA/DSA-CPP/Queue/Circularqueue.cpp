#include <bits/stdc++.h>
using namespace std;

template <typename T>

class Queue
{
    int size;
    int front;
    int rear;
    T *arr;

public:
    Queue(int length)
    {
        size = length;
        front = rear = 0;
        arr = new T[size];
    }

    int queueSize()
    {
        int count = 0;
        for (int i = (front + 1); i <= rear; i++)
        {
            count++;
        }
        return count;
    }

    bool isEmpty()
    {
        return (front == rear);
    }

    bool isFull()
    {
        return (front == ((rear + 1) % size));
    }

    void enqueue(T val)
    {
        if (isFull())
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        rear = (rear + 1) % size;
        arr[rear] = val;
        cout << "Inserted element: " << val << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        front = (front + 1) % size;
        cout << "Deleted element: " << arr[front] << endl;
    }

    T queueFront()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        return arr[front + 1];
    }

    T queueRear()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        return arr[rear];
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        cout << "Printing..." << endl;
        if (rear >= front)
        {
            for (int i = (front + 1); i <= rear; i++)
                cout << arr[i] << " ";
        }
        else
        {
            for (int i = (front + 1); i < size; i++)
                cout << arr[i] << " ";

            for (int i = 0; i <= rear; i++)
                cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue<int> q(5);
    q.enqueue(23);
    q.enqueue(56);
    q.enqueue(42);
    q.enqueue(12);
    // q.enqueue(1);
    q.display();
    cout << "Size: " << q.queueSize() << endl;
    cout << "Front element: " << q.queueFront() << endl;
    cout << "Bottom element: " << q.queueRear() << endl;
    q.dequeue();
    q.display();
    cout << "Size: " << q.queueSize() << endl;
    cout << "Front element: " << q.queueFront() << endl;
    cout << "Bottom element: " << q.queueRear() << endl;
    q.enqueue(10);
    q.display();
    if (q.isFull())
    {
        cout << "Full" << endl;
    }
    if (q.isEmpty())
    {
        cout << "Empty" << endl;
    }

    return 0;
}
