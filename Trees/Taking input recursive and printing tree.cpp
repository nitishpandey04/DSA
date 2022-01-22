#include <iostream>
#include "TreeNode.h"

using namespace std;

TreeNode<int>* takeInput() {
    int rootData, numChildren;
    cout << "Enter data: ";
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    cout << "Number of children of " << rootData << ": ";
    cin >> numChildren;
    for (int i = 0 ; i < numChildren ; i ++) {
        TreeNode<int>* child = takeInput();
        root -> children.push_back(child);
    }
    return root;    
}

void printTree(TreeNode<int>* root) {
    if (root == NULL) return;
    cout << root -> data << " : ";
    for (int i = 0 ; i < root -> children.size() ; i ++) {
        cout << root -> children[i] -> data << " ";
    }
    cout << "\n";
    for (int i = 0 ; i < root -> children.size() ; i ++) {
        printTree(root -> children[i]);
    }
}

void deallocate(TreeNode<int>* root) {
    if (root == NULL) return;
    for (int i = 0 ; i < root -> children.size() ; i ++) {
        deallocate(root -> children[i]);
    }
    delete root;
}

int main() {

    TreeNode<int>* root = takeInput();
    printTree(root);
    deallocate(root);

    return 0;
}
