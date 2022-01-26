#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>

using namespace std;

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cout << "Enter root data: \n";
    cin >> rootData;
    if (rootData == -1) return NULL;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* front = q.front();
        q.pop();
        int leftData;
        cout << "Enter left child of " << front -> data << "\n";
        cin >> leftData;
        if (leftData != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftData);
            front -> left = leftNode;
            q.push(leftNode);
        }
        int rightData;
        cout << "Enter the right child of " << front -> data << "\n";
        cin >> rightData;
        if (rightData != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightData);
            front -> right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printBinaryTree(BinaryTreeNode<int>* root) {
    if (root == NULL) return;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* front = q.front();
        q.pop();
        cout << front -> data << ": ";
        if (front -> left != NULL) {
            cout << "L" << front -> left -> data << " ";
            q.push(front -> left);
        }
        if (front -> right != NULL) {
            cout << "R" << front -> right -> data;
            q.push(front -> right);
        }
        cout << "\n";
    }
}

int main() {

    BinaryTreeNode<int>* root = takeInput();
    printBinaryTree(root);
    delete root;

    return 0;
}