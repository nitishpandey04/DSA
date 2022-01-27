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

int numNodes(BinaryTreeNode<int>* root) {
    if (root == NULL) return 0;
    return 1 + numNodes(root -> left) + numNodes(root -> right);
}

bool isNodePresent(BinaryTreeNode<int>* root, int x) {
    if (root == NULL) return false;
    if (root -> data == x) return true;
    if (isNodePresent(root -> left, x)) return true;
    if (isNodePresent(root -> right, x)) return true;
    return false;
}

int height(BinaryTreeNode<int>* root) {
    if (root == NULL) return 0;
    return 1 + max(height(root -> left), height(root -> right));
}

void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    if (root == NULL) return;
    mirrorBinaryTree(root -> left);
    mirrorBinaryTree(root -> right);
    BinaryTreeNode<int>* temp = root -> right;
    root -> right = root -> left;
    root -> left = temp;
}

void inOrder(BinaryTreeNode<int>* root) {
    if (root == NULL) return;
    inOrder(root -> left);
    cout << root -> data << " ";
    inOrder(root -> right);
}

void preOrder(BinaryTreeNode<int>* root) {
	if (root == NULL) return;
    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}

void postOrder(BinaryTreeNode<int>* root) {
    if (root == NULL) return;
    postOrder(root -> left);
    postOrder(root -> right);
    cout << root -> data << " ";
}

BinaryTreeNode<int>* buildTreePreAndInHelper(int* preorder, int* inorder, int preS, int preE, int inS, int inE) {
    if (preS > preE) return NULL;
    int rootData = preorder[preS], rootIndex;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    for (int i = inS; i <= inE ; i ++) {
        if (inorder[i] == rootData) {
            rootIndex = i;
            break;
        }
    }
    int lps = preS + 1; lis = inS; lie = rootIndex - 1; lpe = lie - lis + lps;
    BinaryTreeNode<int>* left = buildTreePreAndInHelper(preorder, inorder, lps, lpe, lis, lie);
    BinaryTreeNode<int>* right = buildTreePreAndInHelper(preorder, inorder, lpe + 1, preE, rootIndex + 1, inE);
    root -> left = left;
    root -> right = right;
    return root;
}

BinaryTreeNodePreIn<int>* buildTreePreAndIn(int *preorder, int *inorder, int size) {
    // build tree using pre & inorder traversal of binary tree assuming there are no duplicates
    return buildTreePreAndInHelper(preorder, inorder, 0, size - 1, 0, size - 1);
}

BinaryTreeNode<int>* buildTreePostAndInHelper(int* postorder, int* inorder, int postS, int postE, int inS, int inE) {
    if (postS > postE) return NULL;
    int rootData = postorder[postE], rootIndex;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    for (int i = inS ; i <= inE ; i ++) {
        if (inorder[i] == rootData) {
            rootIndex = i;
            break;
        }
    }
    int lps = postS, lis = inS, lie = rootIndex - 1, lpe = lie - lis + lps;
    BinaryTreeNode<int>* left = buildTreePostAndInHelper(postorder, inorder, lps, lpe, lis, lie);
    BinaryTreeNode<int>* right = buildTreePostAndInHelper(postorder, inorder, lpe + 1, postE - 1, rootIndex + 1, inE);
    root -> left = left;
    root -> right = right;
    return root;
}

BinaryTreeNode<int>* buildTreePostAndIn(int *postorder, int *inorder, int size) {
    // build tree using post & inorder traversal of binary tree assuming there are no duplicates
    return buildTreePostAndInHelper(postorder, inorder, 0, size - 1, 0, size - 1);
}

int main() {

    // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    BinaryTreeNode<int>* root = takeInput();
    printBinaryTree(root);
    cout << "Number of nodes: " << numNodes(root) << "\n";
    cout << "Is 7 present in the tree: " << (isNodePresent(root, 7) ? "Yes\n" : "No\n");
    cout << "The height of binary tree is " << height(root) << "\n";
    cout << "Inorder Traversal: "; inOrder(root); cout << "\n";
    cout << "Preorder Traversal: "; preOrder(root); cout << "\n";
    cout << "Postorder Traversal: "; postOrder(root); cout << "\n";
    delete root;

    return 0;
}
