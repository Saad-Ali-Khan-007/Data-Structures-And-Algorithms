#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

class saad_lab8
{
private:
    Node *rear;

public:
    saad_lab8() : rear(nullptr) {}

    void enqueue(int val)
    {
        Node *newNode = new Node(val);
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

    int dequeue()
    {
        if (!rear)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        Node *front = rear->next;
        int val = front->data;
        if (rear == front)
        {
            rear = nullptr;
        }
        else
        {
            rear->next = front->next;
        }
        delete front;
        return val;
    }

    bool isEmpty()
    {
        return rear == nullptr;
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
    saad_lab8 cq;
    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.display();
    cq.dequeue();
    cq.display();

    return 0;
}
