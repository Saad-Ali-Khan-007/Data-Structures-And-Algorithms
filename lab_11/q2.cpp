#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

class saad_lab11
{
public:
    TreeNode *root;

    saad_lab11() : root(nullptr) {}

    void insert(int value)
    {
        root = insertRec(root, value);
    }

    TreeNode *findLCA(TreeNode *node, int n1, int n2)
    {
        if (!node)
            return nullptr;

        if (n1 < node->val && n2 < node->val)
            return findLCA(node->left, n1, n2);

        if (n1 > node->val && n2 > node->val)
            return findLCA(node->right, n1, n2);

        return node;
    }

private:
    TreeNode *insertRec(TreeNode *node, int value)
    {
        if (!node)
            return new TreeNode(value);
        if (value < node->val)
            node->left = insertRec(node->left, value);
        else
            node->right = insertRec(node->right, value);
        return node;
    }
};

int main()
{
    saad_lab11 tree;
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(5);
    tree.insert(15);
    tree.insert(25);
    tree.insert(35);

    int n1 = 5, n2 = 15;
    TreeNode *lca = tree.findLCA(tree.root, n1, n2);
    if (lca)
        cout << "LCA of " << n1 << " and " << n2 << " is: " << lca->val << endl;
    else
        cout << "LCA not found." << endl;

    return 0;
}
