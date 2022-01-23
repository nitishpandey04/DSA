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

void deallocate(TreeNode<int>* root) {
    // perfect example of post order traversal
    if (root == NULL) return;
    for (int i = 0 ; i < root -> children.size() ; i ++) {
        deallocate(root -> children[i]);
    }
    delete root;
}

int numNodes(TreeNode<int>* root) {
    if (root == NULL) return 0;
    int ans = 1;
    for (int i = 0 ; i < root -> children.size() ; i ++) {
        ans += numNodes(root -> children[i]);
    }
    return ans;
}

int sumOfNodes(TreeNode<int>* root) {
    if (root == NULL) return INT32_MIN;
    int ans = root -> data;
    for (int i = 0 ; i < root -> children.size() ; i ++) {
        ans += sumOfNodes(root -> children[i]);
    }
    return ans;
}

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    if (root == NULL) return root;
    TreeNode<int>* ans = root;
    for (int i = 0 ; i < root -> children.size() ; i ++) {
        TreeNode<int>* smallerans = maxDataNode(root -> children[i]);
        if (smallerans -> data > ans -> data) ans = smallerans;
    }
    return ans;
}

int getHeight(TreeNode<int>* root) {
    if (root == NULL) return 0;
    int ans = 0;
    for (int i = 0 ; i < root -> children.size() ; i ++) {
        int smallerans = getHeight(root -> children[i]);
        if (smallerans > ans) ans = smallerans;
    }
    return ans + 1;
}

void printAtLevelK(TreeNode<int>* root, int k) {
    if (root == NULL) return;
    if (k == 0) {
        cout << root -> data << " ";
        return;
    }
    for (int i = 0 ; i < root -> children.size() ; i ++) {
        printAtLevelK(root -> children[i], k - 1);
    }
}

int getLeafNodeCount(TreeNode<int>* root) {
    if (root == NULL) return 0;
    if (root -> children.size() == 0) return 1;
    int ans = 0;
    for (int i = 0 ; i < root -> children.size() ; i ++) {
        ans += getLeafNodeCount(root -> children[i]);
    }
    return ans;
}

void preOrderTraversal(TreeNode<int>* root) {
    if (root == NULL) return;
    cout << root -> data << " ";
    for (int i = 0 ; i < root -> children.size() ; i ++) {
        preOrderTraversal(root -> children[i]);
    }
}

void postOrderTraversal(TreeNode<int>* root) {
    if (root == NULL) return;
    for (int i = 0 ; i < root -> children.size() ; i ++) {
        postOrderTraversal(root -> children[i]);
    }
    cout << root -> data << " ";
}

int main() {

    // 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0

    TreeNode<int>* root = takeInput();
    cout << "Number of nodes: " << numNodes(root) << "\n";
    cout << "Sum of nodes: " << sumOfNodes(root) << "\n";
    cout << "Max data node: " << maxDataNode(root) -> data << "\n";
    cout << "Height of tree: " << getHeight(root) << "\n";
    cout << "Nodes at level 2: "; printAtLevelK(root, 2); cout << "\n";
    cout << "Number of leaf nodes: " << getLeafNodeCount(root) << "\n";
    cout << "Preorder traversal: "; preOrderTraversal(root); cout << "\n";
    cout << "Postorder traversal: "; postOrderTraversal(root);
    // deallocate(root);
    delete root; // destructor updated

    return 0;
}