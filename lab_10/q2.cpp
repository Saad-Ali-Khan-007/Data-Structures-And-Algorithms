#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

bool isMirror(Node *leftSub, Node *rightSub)
{

    if (leftSub == nullptr && rightSub == nullptr)
    {
        return true;
    }

    if (leftSub == nullptr || rightSub == nullptr)
    {
        return false;
    }

    return (leftSub->data == rightSub->data) &&
           isMirror(leftSub->left, rightSub->right) &&
           isMirror(leftSub->right, rightSub->left);
}

bool isSymmetric(Node *root)
{

    if (root == nullptr)
    {
        return true;
    }

    return isMirror(root->left, root->right);
}

int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    if (isSymmetric(root))
    {
        cout << "true";
    }
    else
        cout << "false";

    return 0;
}
