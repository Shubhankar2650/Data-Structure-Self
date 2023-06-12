#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insert(Node *root, int n)
{
    if (root == NULL)
    {
        return (new Node(n));
    }
    if (n < root->data)
    {
        root->left = insert(root->left, n);
    }
    else if (n > root->data)
    {
        root->right = insert(root->right, n);
    }
    return root;
}

void inoderTraversal(Node *root)
{
    if (root != NULL)
    {
        inoderTraversal(root->left);
        cout << root->data << ", ";
        inoderTraversal(root->right);
    }
}

Node * dellete(Node* root){
    if(root == NULL) return root;
    if(root)

    return root;
}
int main()
{
    Node *binaryTreeRoot = new Node(40);
    insert(binaryTreeRoot, 10);
    insert(binaryTreeRoot, 30);
    insert(binaryTreeRoot, 50);
    insert(binaryTreeRoot, 60);
    insert(binaryTreeRoot, 55);

    inoderTraversal(binaryTreeRoot);
}