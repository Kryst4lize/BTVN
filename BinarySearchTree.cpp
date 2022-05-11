// C++ program to demonstrate insertion
// in a BST recursively.
#include <iostream>
using namespace std;

class BST
{
    int data;
    BST* left, * right;

public:
    // Default constructor. ojojoj
    BST();

    // Parameterized constructor.
    BST(int);

    // Insert function node
    BST* Insert(BST*, int);

    // Inorder traversal.
    void Inorder(BST*);
};

// Default Constructor definition.
BST::BST()
    : data(0)
    , left(NULL)
    , right(NULL)
{
}

// Parameterized Constructor definition.
BST::BST(int data)
{
    data = data;
    left = right = NULL;
}

// Insert function definition.
BST* BST::Insert(BST* root, int data)
{
    if (!root)
    {
        // Insert the first node, if root is NULL.
        return new BST(data);
    }

    // Insert data.
    if (data == root->data) {
        return root;
    }
    if (data > root->data)
    {
        // Insert right node data, if the 'value'
        // to be inserted is greater than 'root' node data.

        // Process right nodes.
        root->right = Insert(root->right, data);
    }
    if (data < root->data) 
    {
        // Insert left node data, if the 'value'
        // to be inserted is greater than 'root' node data.

        // Process left nodes.
        root->left = Insert(root->left, data);
    }

    // Return 'root' node, after insertion.
    return root;
}

// Inorder traversal function.
// This gives data in sorted order.
void BST::Inorder(BST* root)
{
    if (!root) {
        return;
    }
    Inorder(root->left);
    cout << root->data << endl;
    Inorder(root->right);
}

// Driver code
int mainb()
{
    BST b, * root = NULL;
    root=b.Insert(root, 50);
    b.Insert(root, 50);
    b.Insert(root, 30);
    b.Insert(root, 20);
    b.Insert(root, 40);
    b.Insert(root, 70);
    b.Insert(root, 60);
    b.Insert(root, 80);
    b.Insert(root, 20);
    b.Insert(root, 100);
    b.Insert(root, 90);

    b.Inorder(root);
    return 0;
}