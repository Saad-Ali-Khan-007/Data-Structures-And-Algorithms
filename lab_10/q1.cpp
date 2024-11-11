#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

class saad_lab10
{
private:
    TreeNode *root;

public:
    saad_lab10() : root(nullptr) {}

    void insert(int value)
    {
        root = insertNode(root, value);
    }

    bool search(int value)
    {
        return searchRec(root, value);
    }

    void preorderTraversal()
    {
        preorderRec(root);
        cout << endl;
    }

    void postorderTraversal()
    {
        postorderRec(root);
        cout << endl;
    }

private:
    TreeNode *insertNode(TreeNode *node, int value)
    {
        if (!node)
            return new TreeNode(value);

        queue<TreeNode *> q;
        q.push(node);

        while (!q.empty())
        {
            TreeNode *current = q.front();
            q.pop();

            if (!current->left)
            {
                current->left = new TreeNode(value);
                return node;
            }
            else
            {
                q.push(current->left);
            }

            if (!current->right)
            {
                current->right = new TreeNode(value);
                return node;
            }
            else
            {
                q.push(current->right);
            }
        }
        return node;
    }

    bool searchRec(TreeNode *node, int value)
    {
        if (!node)
            return false;
        if (node->val == value)
            return true;
        return searchRec(node->left, value) || searchRec(node->right, value);
    }

    void preorderRec(TreeNode *node)
    {
        if (!node)
            return;
        cout << node->val << " ";
        preorderRec(node->left);
        preorderRec(node->right);
    }

    void postorderRec(TreeNode *node)
    {
        if (!node)
            return;
        postorderRec(node->left);
        postorderRec(node->right);
        cout << node->val << " ";
    }
};

int main()
{
    saad_lab10 tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(17);

    cout << "Searching for 7: " << (tree.search(7) ? "Found" : "Not found") << endl;
    cout << "Searching for 20: " << (tree.search(20) ? "Found" : "Not found") << endl;

    cout << "Pre-order traversal: ";
    tree.preorderTraversal();

    cout << "Post-order traversal: ";
    tree.postorderTraversal();

    return 0;
}
