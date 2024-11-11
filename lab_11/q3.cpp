#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = right = nullptr;
    }
};

class saad_lab11
{
private:
    Node *root;

    int sumOfNodes(Node *node)
    {
        if (node == nullptr)
            return 0;

        return node->data + sumOfNodes(node->left) + sumOfNodes(node->right);
    }

public:
    saad_lab11()
    {
        root = nullptr;
    }

    void insert(int value)
    {
        root = insertNode(root, value);
    }

    Node *insertNode(Node *node, int value)
    {
        if (node == nullptr)
            return new Node(value);

        if (value < node->data)
            node->left = insertNode(node->left, value);
        else if (value > node->data)
            node->right = insertNode(node->right, value);

        return node;
    }

    int sum()
    {
        return sumOfNodes(root);
    }
};

int main()
{
    saad_lab11 tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    int totalSum = tree.sum();
    cout << "Sum of all nodes: " << totalSum << endl;

    return 0;
}
