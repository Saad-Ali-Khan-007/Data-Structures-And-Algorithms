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
    bool isPalindrome(Node *head)
    {
        if (!head || !head->next)
            return true;

        Node *slow = head;
        Node *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node *prev = nullptr;
        while (slow)
        {
            Node *next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        Node *left = head;
        Node *right = prev;
        while (right)
        {
            if (left->data != right->data)
                return false;
            left = left->next;
            right = right->next;
        }
        return true;
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

    Node *palindromeList = new Node(1);
    palindromeList->next = new Node(2);
    palindromeList->next->next = new Node(2);
    palindromeList->next->next->next = new Node(1);
    cout << "Is palindrome: " << (solution.isPalindrome(palindromeList) ? "true" : "false") << endl;

    return 0;
}
