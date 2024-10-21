#include <iostream>
using namespace std;

class saad_lab6
{
private:
    int queue[100];
    int front, rear;
    int capacity;

public:
    saad_lab6(int size = 100)
    {
        front = 0;
        rear = -1;
        capacity = size;
    }

    void enqueue(int element)
    {
        if (rear == capacity - 1)
        {
            cout << "Queue Overflow! Cannot enqueue element." << endl;
            return;
        }
        queue[++rear] = element;
        cout << "Enqueued: " << element << endl;
    }

    void dequeue()
    {
        if (front > rear)
        {
            cout << "Queue Underflow! Cannot dequeue element." << endl;
        }
        else
        {
            cout << "Dequeued: " << queue[front++] << endl;
        }
    }

    void display()
    {
        if (front > rear)
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
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
    queue.display();

    queue.dequeue();
    queue.display();

    return 0;
}
