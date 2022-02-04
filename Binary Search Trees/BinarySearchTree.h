#include <iostream>
using namespace std;
#include "BinaryTreeNode.h"
#include <climits>
class BST {

    BinaryTreeNode<int>* root;

    int minimum(BinaryTreeNode<int>* root) {
        if (root == NULL) return INT_MAX;
        if (root -> left == NULL && root -> right == NULL) return root -> data;
        return minimum(root -> left);
    }

    bool hasData(int d, BinaryTreeNode<int>* root) {
        if (root == NULL) return false;
        if (root -> data == d) return true;
        if (hasData(d, root -> left)) return true;
        if (hasData(d, root -> right)) return true;
        return false;
    }

    void print(BinaryTreeNode<int>* root) {
        if (root == NULL) return;
        cout << root -> data << ":";
        if (root -> left != NULL) {
            cout << "L:" << root -> left -> data << ",";
        }
        if (root -> right != NULL) {
            cout << "R:" << root -> right -> data;
        }
        cout << "\n";
        print(root -> left);
        print(root -> right);
    }

    BinaryTreeNode<int>* insert(int d, BinaryTreeNode<int>* root) {
        if (root == NULL) {
            root = new BinaryTreeNode<int>(d);
            return root;
        }
        if (root -> data <= d) {
            BinaryTreeNode<int>* rightAns = insert(d, root -> right);
            root -> right = rightAns;
            return root;
        } else {
            BinaryTreeNode<int>* leftAns = insert(d, root -> left);
            root -> left = leftAns;
            return root;
        }
    }

    BinaryTreeNode<int>* remove(int d, BinaryTreeNode<int>* root) {
        if (root == NULL) return NULL;
        if (root -> data > d) {
            BinaryTreeNode<int>* leftAns = remove(d, root -> left);
            root -> left = leftAns;
            return root;
        }
        if (root -> data < d) {
            BinaryTreeNode<int>* rightAns = remove(d, root -> right);
            root -> right = rightAns;
            return root;
        }
        if (root -> left == NULL && root -> right == NULL) {
            delete root;
            return NULL;
        }
        if (root -> left != NULL && root -> right == NULL) return root -> left;
        if (root -> left == NULL && root -> right != NULL) return root -> right;
        int min = minimum(root -> right);
        root -> data = min;
        BinaryTreeNode<int>* rightAns = remove(min, root -> right);
        root -> right = rightAns;
        return root;
    }
    
    public:
    
    BST() {
        root = NULL;
    }

    ~BST() {
        delete root;
    }

    bool hasData(int d) {
        return hasData(d, root);
    }

    void insert(int d) {
        root = insert(d, root);
    }

    void remove(int d) {
        root = remove(d, root);
    }

    void print() {
        print(root);
    }
};