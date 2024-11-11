#include <iostream>
using namespace std;

class DoubleNode
{
public:
    int data;
    DoubleNode *prev;
    DoubleNode *next;

    DoubleNode(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class saad_lab9_Deque
{
private:
    DoubleNode *front;
    DoubleNode *rear;

public:
    saad_lab9_Deque() : front(nullptr), rear(nullptr) {}

    void insertFront(int value)
    {
        DoubleNode *newNode = new DoubleNode(value);
        if (!front)
        {
            front = rear = newNode;
        }
        else
        {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    void insertRear(int value)
    {
        DoubleNode *newNode = new DoubleNode(value);
        if (!rear)
        {
            front = rear = newNode;
        }
        else
        {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
    }

    void deleteFront()
    {
        if (!front)
        {
            cout << "Deque is empty" << endl;
            return;
        }
        DoubleNode *temp = front;
        front = front->next;
        if (front)
            front->prev = nullptr;
        else
            rear = nullptr;
        delete temp;
    }

    void deleteRear()
    {
        if (!rear)
        {
            cout << "Deque is empty" << endl;
            return;
        }
        DoubleNode *temp = rear;
        rear = rear->prev;
        if (rear)
            rear->next = nullptr;
        else
            front = nullptr;
        delete temp;
    }

    void display()
    {
        DoubleNode *temp = front;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    saad_lab9_Deque deque;
    deque.insertFront(10);
    deque.insertRear(20);
    deque.insertFront(5);
    deque.insertRear(25);

    cout << "Deque contents after inserts: ";
    deque.display();

    deque.deleteFront();
    cout << "Deque contents after deleting front: ";
    deque.display();

    deque.deleteRear();
    cout << "Deque contents after deleting rear: ";
    deque.display();

    return 0;
}
