#include <iostream>
#include <queue>
using namespace std;

// Defn - Every node has atmost two childreen
// we typically represnt using linked structure.

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

// 👌 Defth First Search traversal technique for binary tree

void inoderTraversal(Node *root)
{
    if (root != NULL)
    {
        inoderTraversal(root->left);
        cout << root->data << ", ";
        inoderTraversal(root->right);
    }
}

void preoderTraversal(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << ", ";
        inoderTraversal(root->left);
        inoderTraversal(root->right);
    }
}

void postoderTraversal(Node *root)
{
    if (root != NULL)
    {
        inoderTraversal(root->left);
        inoderTraversal(root->right);
        cout << root->data << ", ";
    }
}

//  // Time complexi ty - O(n);
// Auxilary Space - O(h) (height of tree) for all above three traversal

/* ✒️Q2. Height of the binary tree-
    it is the nmaximu no. of node from root to the leaf part

    there is one more convention in which we find the no. of edges from root to leaf node
    in case of empty tree: -1
    in case of only root node: 0

*/

int height(Node *root)
{
    if (root == NULL)
        return 0;
    else
    {
        return max(height(root->left), height(root->right)) + 1;
    }
}

// Q. print nodes at distance k

void nodeAt_K_distance(Node *root, int k)
{
    if (root == NULL)
        return;
    if (k == 0)
    {
        cout << root->data << ", ";
        return;
    }
    else
    {
        nodeAt_K_distance(root->left, k - 1);
        nodeAt_K_distance(root->right, k - 1);
    }
}

// Best case- 0(1)
// Time complexity - O(n)

// Level Order Travesal
void levelOderTraversal(Node *root)
{
    int h = height(root);
    for (int i = 0; i <= h; i++)
    {
        nodeAt_K_distance(root, i);
    }
}

// level order traversal using queue

void levelOrderQueue(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (q.empty() == false)
    {
        q.pop();
        if (root->left != NULL)
        {
            q.push(root->left);
        }
        if (root->right != NULL)
        {
            q.push(root->right);
        }
    }
}

int main()
{
    /*
    1. Traversal of binary tree
    2. Height of Binary Tree
    3. Count leaf and non leaf in Binary tee
    4. Check if Btree is Balanced or not
    5. Check if Btree is BST
    6. search in BST without using recurrsion
    */

    Node *binaryTreeRoot = NULL;
    binaryTreeRoot = new Node(10);
    binaryTreeRoot->left = new Node(5);
    binaryTreeRoot->right = new Node(20);
    binaryTreeRoot->left->right = new Node(7);
    binaryTreeRoot->right->left = new Node(15);
    binaryTreeRoot->right->right = new Node(30);

    inoderTraversal(binaryTreeRoot);

    cout << height(binaryTreeRoot) << endl;

    // cout << "Node at kth distance, Enter k";
    // int k;
    // cin >> k;
    // nodeAt_K_distance(binaryTreeRoot, k);

    // levelOderTraversal(binaryTreeRoot);
    levelOrderQueue(binaryTreeRoot);
}