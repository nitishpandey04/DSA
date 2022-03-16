#include <iostream>
using namespace std;
#include "BinaryTreeNode.h"
#include <climits>
class BST {

    BinaryTreeNode<int>* root;

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
            root -> left = remove(d, root -> left);
            return root;
        } else if (root -> data < d) {
            root -> right = remove(d, root -> right);
            return root;
        } else {
            if (root -> left == NULL && root -> right == NULL) {
                delete root;
                return NULL;
            } else if (root -> left == NULL) {
                BinaryTreeNode<int>* temp = root -> right;
                root -> right = NULL;
                delete root;
                return temp;
            } else if (root -> right == NULL) {
                BinaryTreeNode<int>* temp = root -> left;
                root -> left = NULL;
                delete root;
                return temp;
            } else {
                BinaryTreeNode<int>* rightMin = root -> right;
                while (rightMin -> left != NULL) {
                    rightMin = rightMin -> left;
                }
                root -> data = rightMin -> data;
                root -> right = remove(rightMin -> data, root -> right);
                return root;
            }
        }
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