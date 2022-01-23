#include <iostream>
#include <queue>
#include "TreeNode.h"

using namespace std;

TreeNode<int>* takeInput() {
    int rootData;
    cout << "Enter root data: ";
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode<int>* firstNode = q.front();
        q.pop();
        int numChildren;
        cout << "Enter the number of children of " << firstNode -> data << ": ";
        cin >> numChildren;
        for (int i = 0 ; i < numChildren ; i ++) {
            int childData;
            cout << "Enter data of " << i + 1 << "th child of " << firstNode -> data << ": ";
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            firstNode -> children.push_back(child);
            q.push(child);
        }
    }
    return root;
}

void printTree(TreeNode<int>* root) {
    queue<TreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode<int>* frontNode = q.front();
        q.pop();
        cout << frontNode -> data << ": ";
        for (int i = 0 ; i < frontNode -> children.size() ; i ++) {
            cout << frontNode -> children[i] -> data << " ";
            q.push(frontNode -> children[i]);
        }
        cout << "\n";
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
