#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

class saad_lab9_CircularQueue
{
private:
    Node *rear;

public:
    saad_lab9_CircularQueue() : rear(nullptr) {}

    void enqueue(int value)
    {
        Node *newNode = new Node(value);
        if (!rear)
        {
            rear = newNode;
            rear->next = rear;
        }
        else
        {
            newNode->next = rear->next;
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue()
    {
        if (!rear)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        Node *front = rear->next;
        if (rear == front)
        {
            delete front;
            rear = nullptr;
        }
        else
        {
            rear->next = front->next;
            delete front;
        }
    }

    void display()
    {
        if (!rear)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        Node *temp = rear->next;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != rear->next);
        cout << endl;
    }
};
int main()
{
    saad_lab9_CircularQueue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);

    cout << "Queue contents after enqueues: ";
    queue.display();

    queue.dequeue();
    cout << "Queue contents after one dequeue: ";
    queue.display();

    queue.dequeue();
    cout << "Queue contents after two dequeues: ";
    queue.display();

    return 0;
}
