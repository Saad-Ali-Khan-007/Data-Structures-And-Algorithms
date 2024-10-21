#include <iostream>
using namespace std;

class saad_lab6
{
private:
    int deque[100];
    int frontIndex, rearIndex, currentSize, capacity;

public:
    saad_lab6(int size = 100)
    {
        frontIndex = -1;
        rearIndex = -1;
        currentSize = 0;
        capacity = size;
    }

    bool isEmpty()
    {
        return (currentSize == 0);
    }

    bool isFull()
    {
        return (currentSize == capacity);
    }

    void insertFront(int element)
    {
        if (isFull())
        {
            cout << "Deque Overflow! Cannot insert element at the front." << endl;
            return;
        }

        if (frontIndex == -1)
        {
            frontIndex = 0;
            rearIndex = 0;
        }
        else
        {
            frontIndex = (frontIndex - 1 + capacity) % capacity;
        }

        deque[frontIndex] = element;
        currentSize++;
        cout << "Inserted at front: " << element << endl;
    }

    void insertRear(int element)
    {
        if (isFull())
        {
            cout << "Deque Overflow! Cannot insert element at the rear." << endl;
            return;
        }

        if (rearIndex == -1)
        {
            frontIndex = 0;
            rearIndex = 0;
        }
        else
        {
            rearIndex = (rearIndex + 1) % capacity;
        }

        deque[rearIndex] = element;
        currentSize++;
        cout << "Inserted at rear: " << element << endl;
    }

    void deleteFront()
    {
        if (isEmpty())
        {
            cout << "Deque Underflow! Cannot delete element from the front." << endl;
            return;
        }

        cout << "Deleted front: " << deque[frontIndex] << endl;
        frontIndex = (frontIndex + 1) % capacity;
        currentSize--;
    }

    void deleteRear()
    {
        if (isEmpty())
        {
            cout << "Deque Underflow! Cannot delete element from the rear." << endl;
            return;
        }

        cout << "Deleted rear: " << deque[rearIndex] << endl;
        rearIndex = (rearIndex - 1 + capacity) % capacity;
        currentSize--;
    }

    int size()
    {
        return currentSize;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Deque is empty!" << endl;
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
    saad_lab6 deque(5);

    deque.insertFront(10);
    deque.insertRear(20);
    deque.insertFront(30);
    deque.display();

    deque.deleteFront();
    deque.display();

    deque.insertRear(40);
    deque.insertRear(50);
    deque.display();

    deque.deleteRear();
    deque.display();

    cout << "Size of Deque: " << deque.size() << endl;

    return 0;
}
