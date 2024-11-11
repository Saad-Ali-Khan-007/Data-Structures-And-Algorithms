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
public:
    Node *mergeTwoLists(Node *list1, Node *list2)
    {
        if (!list1)
            return list2;
        if (!list2)
            return list1;

        Node *head = nullptr;
        if (list1->data < list2->data)
        {
            head = list1;
            list1 = list1->next;
        }
        else
        {
            head = list2;
            list2 = list2->next;
        }

        Node *current = head;
        while (list1 && list2)
        {
            if (list1->data < list2->data)
            {
                current->next = list1;
                list1 = list1->next;
            }
            else
            {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }
        current->next = list1 ? list1 : list2;
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

    Node *list1 = new Node(1);
    list1->next = new Node(2);
    list1->next->next = new Node(4);
    Node *list2 = new Node(1);
    list2->next = new Node(3);
    list2->next->next = new Node(4);
    Node *mergedList = solution.mergeTwoLists(list1, list2);
    solution.printList(mergedList);

    return 0;
}
