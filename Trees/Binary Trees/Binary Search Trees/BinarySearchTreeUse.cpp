#include <iostream>
#include "BinarySearchTree.h"
#include "BinaryTreeNode.h"
#include <climits>
#include "Node.h"

using namespace std;

void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
	if (root == NULL) return;
    if (root -> data > k1) elementsInRangeK1K2(root -> left, k1, k2);
    if (root -> data >= k1 && root -> data <= k2) cout << root -> data << " ";
    if (root -> data < k2) elementsInRangeK1K2(root -> right, k1, k2);
}

bool isBSTHelper(BinaryTreeNode<int>* root, int min = INT_MIN, int max = INT_MAX) {
    if (root == NULL) return true;
    if (root -> data < min || root -> data > max) return false;
    int isLeftOk = isBSTHelper(root -> left, min, root -> data - 1);
    int isRightOk = isBSTHelper(root -> right, root -> data, max);
    return isLeftOk && isRightOk;
}

bool isBST(BinaryTreeNode<int> *root) {
	return isBSTHelper(root);
}

BinaryTreeNode<int>* constructTreeHelper(int* input, int si, int ei) {
	if (si > ei) return NULL;
    int mid = (si + ei) / 2;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(input[mid]);
    BinaryTreeNode<int>* left = constructTreeHelper(input, si, mid - 1);
    BinaryTreeNode<int>* right = constructTreeHelper(input, mid + 1, ei);
    root -> left = left;
    root -> right = right;
    return root;
}

BinaryTreeNode<int>* constructTree(int *input, int n) {
	return constructTreeHelper(input, 0, n - 1);
}

pair<Node<int>*, Node<int>*> constructLinkedListHelper(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        pair<Node<int>*, Node<int>*> p = {NULL, NULL};
        return p;
    }
    Node<int>* head = NULL;
    Node<int>* tail = NULL;
    pair<Node<int>*, Node<int>*> leftAns = constructLinkedListHelper(root -> left);
    head = leftAns.first;
    tail = leftAns.second;
    if (head == NULL) {
        head = new Node<int>(root -> data);
        tail = head;
    } else {
        tail -> next = new Node<int>(root -> data);
        tail = tail -> next;
    }
    pair<Node<int>*, Node<int>*> rightAns = constructLinkedListHelper(root -> right);
    tail -> next = rightAns.first;
    if (rightAns.second != NULL) tail = rightAns.second;
    pair<Node<int>*, Node<int>*> ans = {head, tail};
    return ans;
}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	return constructLinkedListHelper(root).first;
}

vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
    if (root == NULL) {
        vector<int>* v = new vector<int>();
        return v;
    }
    if (root -> data == data) {
        vector<int>* v = new vector<int>();
        v -> push_back(root -> data);
        return v;
    }
    vector<int>* leftAns = getPath(root -> left, data);
    if (!leftAns -> empty()) {
        leftAns -> push_back(root -> data);
        return leftAns;
    } 
    vector<int>* rightAns = getPath(root -> right, data);
    if (!rightAns -> empty()) {
        rightAns -> push_back(root -> data);
        return rightAns;
    } else return rightAns;
}

int main() {

    BST b;

    b.insert(4);
    b.insert(2);
    b.insert(1);
    b.insert(3);
    b.insert(6);
    b.insert(5);
    b.insert(7);

    b.print();

    b.remove(4);
    b.remove(1);

    b.print();

    return 0;
}