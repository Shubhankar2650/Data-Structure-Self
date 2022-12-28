
#include <iostream>
#include <queue>
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

// 👉 Q. Print left view of binary tree

// ✒️ iterative solution
void leftView(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (q.empty() == false)
    {
        int n = q.size();

        for (int i = 0; i < n; i++)
        {
            Node *temp = q.front();
            q.pop();
            if (i == 0)
                cout << temp->data << " ";
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}

// ✒️recursive solution
// void leftview

int main()
{
    Node *binaryTreeRoot = new Node(10);
    binaryTreeRoot->left = new Node(20);
    binaryTreeRoot->right = new Node(30);
    binaryTreeRoot->left->right = new Node(40);
    binaryTreeRoot->left->left = new Node(50);
    binaryTreeRoot->right->right = new Node(60);

    leftView(binaryTreeRoot);
}
