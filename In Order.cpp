#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int v)
    {
        this->data = v;
        this->left = this->right = NULL;
    }
};

void printPreOrder(Node* node)
{
    if (node == NULL)
        return;

    cout << node->data << " ";

    printPreOrder(node->left);

    printPreOrder(node->right);
}

void printPostOrder(Node* node)
{
    if (node == NULL)
        return;

    printPostOrder(node->left);

    printPostOrder(node->right);

    cout << node->data << " ";
}

int main()
{
    Node* root = new Node(50);
    root->left = new Node(61);
    root->right = new Node(100);
    root->left->left = new Node(105);
    root->left->right = new Node(35);
    root->right->left = new Node(150);
    root->right->right = new Node(400);

    cout << "Preorder: ";
    printPreOrder(root);
    cout << "\n";

    cout << "Postorder: ";
    printPostOrder(root);
    cout << "\n";

    return 0;
}
