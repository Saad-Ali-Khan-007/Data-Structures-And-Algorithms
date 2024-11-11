#include <iostream>
using namespace std;

// Node structure for linked list
struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

// Class saad_lab8 containing solutions to the five problems
class saad_lab8
{
public:
public:
    Node *deleteDuplicates(Node *head)
    {
        if (!head)
            return nullptr;

        Node *current = head;
        while (current && current->next)
        {
            if (current->data == current->next->data)
            {
                Node *temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
            else
            {
                current = current->next;
            }
        }
        return head;
    }

    void printList(Node *head)
    {
        Node *temp = head;
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
    saad_lab8 solution;

    Node *sortedList = new Node(1);
    sortedList->next = new Node(1);
    sortedList->next->next = new Node(2);
    Node *uniqueList = solution.deleteDuplicates(sortedList);
    solution.printList(uniqueList);

    return 0;
}
