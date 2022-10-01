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
        front = rear = -1;
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

    void enqueueR(T val)
    {
        if (isFull())
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        rear++;
        arr[rear] = val;
        cout << "Inserted element: " << arr[rear] << endl;
    }

    void enqueueF(T val)
    {
        int n = -1;
        if (isFull())
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        while (n != front - 1)
        {
            n++;
        }
        arr[front] = val;
        front = n;
        cout << "Inserted element: " << val << endl;
    }

    void dequeueF()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        front++;
        cout << "Deleted element: " << arr[front] << endl;
    }

    void dequeueR()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        int n = -1;
        while (n!=rear-1)
        {
            n++;
        }
        cout << "Deleted element: " << arr[rear] << endl;
        rear = n;
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
        for (int i = (front + 1); i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue<int> q(5);
    q.enqueueR(23);
    q.enqueueR(56);
    q.enqueueR(42);
    q.enqueueR(12);
    q.enqueueR(121);
    q.display();
    cout << "Size: " << q.queueSize() << endl;
    cout << "Front element: " << q.queueFront() << endl;
    cout << "Bottom element: " << q.queueRear() << endl;
    q.dequeueR();
    q.display();
    cout << "Size: " << q.queueSize() << endl;
    cout << "Front element: " << q.queueFront() << endl;
    cout << "Bottom element: " << q.queueRear() << endl;
    q.enqueueF(1);
    q.display();
    return 0;
}
