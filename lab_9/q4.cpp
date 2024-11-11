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

class saad_lab9_DoublyLinkedList
{
public:
    DoubleNode *head;
    DoubleNode *tail;

    saad_lab9_DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insert(int value)
    {
        DoubleNode *newNode = new DoubleNode(value);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void concatenate(saad_lab9_DoublyLinkedList &other)
    {
        if (!other.head)
            return;
        if (!head)
        {
            head = other.head;
            tail = other.tail;
        }
        else
        {
            tail->next = other.head;
            other.head->prev = tail;
            tail = other.tail;
        }
    }

    void display()
    {
        DoubleNode *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

void sortDescending(saad_lab9_DoublyLinkedList &list)
{
    for (DoubleNode *i = list.head; i != nullptr; i = i->next)
    {
        for (DoubleNode *j = i->next; j != nullptr; j = j->next)
        {
            if (i->data < j->data)
            {
                swap(i->data, j->data);
            }
        }
    }
}

int main()
{
    saad_lab9_DoublyLinkedList N;
    for (int i = 2; i <= 10; i += 2)
        N.insert(i);
    for (int i = 1; i < 10; i += 2)
        N.insert(i);
    sortDescending(N);
    cout << "List N after sorting in descending order: ";
    N.display();
}
