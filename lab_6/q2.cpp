#include <iostream>
using namespace std;

class saad_lab6
{
private:
    int queue[100];
    int frontIndex, rearIndex, currentSize, capacity;

public:
    saad_lab6(int size = 100)
    {
        frontIndex = -1;
        rearIndex = -1;
        currentSize = 0;
        capacity = size;
    }

    bool isFull()
    {
        return (currentSize == capacity);
    }

    bool isEmpty()
    {
        return (currentSize == 0);
    }

    void enqueue(int element)
    {
        if (isFull())
        {
            cout << "Circular Queue Overflow!" << endl;
            return;
        }

        rearIndex = (rearIndex + 1) % capacity;
        queue[rearIndex] = element;
        currentSize++;

        if (frontIndex == -1)
            frontIndex = 0;

        cout << "Enqueued: " << element << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Circular Queue Underflow!" << endl;
            return;
        }

        cout << "Dequeued: " << queue[frontIndex] << endl;
        frontIndex = (frontIndex + 1) % capacity;
        currentSize--;
    }

    int front()
    {
        if (isEmpty())
        {
            cout << "Circular Queue is empty!" << endl;
            return -1;
        }
        return queue[frontIndex];
    }

    int rear()
    {
        if (isEmpty())
        {
            cout << "Circular Queue is empty!" << endl;
            return -1;
        }
        return queue[rearIndex];
    }

    int size()
    {
        return currentSize;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Circular Queue is empty!" << endl;
            return;
        }

        cout << "Circular Queue: ";
        int i = frontIndex;
        for (int count = 0; count < currentSize; count++)
        {
            cout << queue[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

int main()
{
    saad_lab6 queue(5);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.display();

    queue.dequeue();
    queue.display();

    queue.enqueue(40);
    queue.enqueue(50);
    queue.enqueue(60); // Circular behavior kicks in
    queue.display();

    cout << "Front: " << queue.front() << endl;
    cout << "Rear: " << queue.rear() << endl;
    cout << "Size: " << queue.size() << endl;

    queue.dequeue();
    queue.display();

    return 0;
}
