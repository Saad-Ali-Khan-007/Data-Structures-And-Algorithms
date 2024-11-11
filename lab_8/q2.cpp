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
    Node *top;

public:
    saad_lab8() : top(nullptr) {}

    void push(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    int pop()
    {
        if (!top)
        {
            cout << "saad_lab8 is empty" << endl;
            return -1;
        }
        int val = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        return val;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void display()
    {
        Node *temp = top;
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

    saad_lab8 saad_lab8;
    saad_lab8.push(10);
    saad_lab8.push(20);
    saad_lab8.push(30);
    saad_lab8.display();
    saad_lab8.pop();
    saad_lab8.display();

    return 0;
}
