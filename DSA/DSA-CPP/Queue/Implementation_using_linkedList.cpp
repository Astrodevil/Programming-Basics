#include <bits/stdc++.h>
using namespace std;

template <typename T>

class node
{
public:
    T data;
    node<T> *next;
};

template <typename T>

class Queue
{
    node<T> *front, *rear;

public:
    Queue()
    {
        front = rear = NULL;
    }

    int queueSize()
    {
        int count = 0;
        node<T> *n = front;
        while (n != NULL)
        {
            count++;
            n = n->next;
        }
        return count;
    }

    bool isEmpty()
    {
        return (rear == NULL);
    }

    bool isFull()
    {
        node<T> *n = new node<T>;
        return (n == NULL);
    }

    void enqueue(T val)
    {
        node<T> *n = new node<T>;
        if (isFull())
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        n->data = val;
        n->next = NULL;
        if (isEmpty())
        {
            rear = front = n;
            cout << "Inserted element: " << val << endl;
            return;
        }
        rear->next = n;
        rear = n;
        cout << "Inserted element: " << val << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        node<T> *n = front;
        front = front->next;
        cout << "Deleted element: " << n->data << endl;
        delete n;
    }

    void traversal()
    {
        cout << "Printing..." << endl;
        node<T> *n = front;
        while (n != NULL)
        {
            cout << n->data << " ";
            n = n->next;
        }
        cout << endl;
    }

    void givenPosition(int index)
    {
        node<T> *n = front;
        for (int i = 0; (i < index - 1 && n != NULL); i++)
        {
            n = n->next;
        }
        if (n != NULL)
        {
            cout << "Element at index " << index << " is: " << n->data << endl;
            return;
        }
        cout << "Invalid index" << endl;
    }

    T queueFront()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        return (front->data);
    }

    T queueRear()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        return (rear->data);
    }
};

int main()
{
    Queue<int> q;
    q.enqueue(56);
    q.enqueue(12);
    q.enqueue(5);
    q.traversal();
    cout << "Front element: " << q.queueFront() << endl;
    cout << "Rear element: " << q.queueRear() << endl;
    cout << "Size: " << q.queueSize() << endl;
    q.givenPosition(1);
    q.dequeue();
    q.traversal();
    cout << "Front element: " << q.queueFront() << endl;
    cout << "Rear element: " << q.queueRear() << endl;
    cout << "Size: " << q.queueSize() << endl;
    return 0;
}
