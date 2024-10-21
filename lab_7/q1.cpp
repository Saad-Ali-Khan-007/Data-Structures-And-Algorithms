#include <iostream>
using namespace std;

class saad_lab7
{
private:
    int *deque;
    int frontIndex, rearIndex, currentSize, capacity;

public:
    saad_lab7(int k)
    {
        capacity = k;
        deque = new int[capacity];
        frontIndex = -1;
        rearIndex = -1;
        currentSize = 0;
    }

    void insertFront(int value)
    {
        if (isFull())
        {
            cout << "The deque is full, cannot insert at the front." << endl;
            return;
        }

        if (isEmpty())
        {
            frontIndex = 0;
            rearIndex = 0;
        }
        else
        {
            frontIndex = (frontIndex - 1 + capacity) % capacity;
        }

        deque[frontIndex] = value;
        currentSize++;
        cout << "Inserted at front: " << value << endl;
    }

    void insertLast(int value)
    {
        if (isFull())
        {
            cout << "The deque is full, cannot insert at the rear." << endl;
            return;
        }

        if (isEmpty())
        {
            frontIndex = 0;
            rearIndex = 0;
        }
        else
        {
            rearIndex = (rearIndex + 1) % capacity;
        }

        deque[rearIndex] = value;
        currentSize++;
        cout << "Inserted at rear: " << value << endl;
    }

    void deleteFront()
    {
        if (isEmpty())
        {
            cout << "The deque is empty, cannot delete from the front." << endl;
            return;
        }

        cout << "Deleted front: " << deque[frontIndex] << endl;
        frontIndex = (frontIndex + 1) % capacity;
        currentSize--;
    }

    void deleteLast()
    {
        if (isEmpty())
        {
            cout << "The deque is empty, cannot delete from the rear." << endl;
            return;
        }

        cout << "Deleted rear: " << deque[rearIndex] << endl;
        rearIndex = (rearIndex - 1 + capacity) % capacity;
        currentSize--;
    }

    int getFront()
    {
        if (isEmpty())
        {
            cout << "Deque is empty." << endl;
            return -1;
        }
        return deque[frontIndex];
    }

    int getRear()
    {
        if (isEmpty())
        {
            cout << "Deque is empty." << endl;
            return -1;
        }
        return deque[rearIndex];
    }

    bool isEmpty()
    {
        return (currentSize == 0);
    }

    bool isFull()
    {
        return (currentSize == capacity);
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Deque is empty." << endl;
            return;
        }

        cout << "Deque: ";
        int i = frontIndex;
        for (int count = 0; count < currentSize; count++)
        {
            cout << deque[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

int main()
{
    saad_lab7 myCircularDeque(3);

    myCircularDeque.insertLast(1);
    myCircularDeque.insertLast(2);
    myCircularDeque.insertFront(3);
    myCircularDeque.insertFront(4);
    cout << "Rear item: " << myCircularDeque.getRear() << endl;
    cout << "Is deque full? " << (myCircularDeque.isFull() ? "True" : "False") << endl;
    myCircularDeque.deleteLast();
    myCircularDeque.insertFront(4);
    myCircularDeque.display();

    return 0;
}
