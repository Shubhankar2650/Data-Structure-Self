
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

int height(Node *root)
{
    if (root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}

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

// 👉 Childreen sum property - check wheather the sum of left and right childreen is equal to the parent node and
//                              return true if it is and also if it has no childreen or null tree return true else false.
bool isCSum(Node *root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    int sum = 0;
    if (root->left != NULL)
    {
        sum += root->left->data;
    }
    if (root->right != NULL)
    {
        sum += root->right->data;
    }

    return (root->data == sum && isCSum(root->left) && isCSum(root->right));
}
// Time complexity = 0(n)
// Auxilary space required = 0(h)

// ✍️ Blanced Binary Search Tree-
int isBST(Node *root)
{
    if (root == NULL)
        return 0;
    int sum = 0;
    if (root->left != NULL)
    {
        sum = sum + 1 + isBST(root->left);
    }
    if (root->right != NULL)
    {
        sum = sum - 1 + isBST(root->right);
    }
    return sum;
}
// ✒️recursive solution

bool isBSTree(Node *root)
{
    if (root == NULL)
        return true;
    int lh = height(root->left);
    int rh = height(root->right);

    return (abs(lh - rh) <= 1 && isBSTree(root->left) && isBSTree(root->right));
}

int main()
{
    // Node *binaryTreeRoot = new Node(10);
    // binaryTreeRoot->left = new Node(20);
    // binaryTreeRoot->right = new Node(30);
    // binaryTreeRoot->left->right = new Node(40);
    // binaryTreeRoot->left->left = new Node(50);
    // binaryTreeRoot->right->right = new Node(60);

    Node *binaryTreeRoot1 = new Node(20);
    binaryTreeRoot1->left = new Node(8);
    binaryTreeRoot1->right = new Node(12);
    binaryTreeRoot1->left->right = new Node(5);
    binaryTreeRoot1->left->left = new Node(3);

    // leftView(binaryTreeRoot);
    // cout << isBSTree(binaryTreeRoot);
    cout << isCSum(binaryTreeRoot1);
}
