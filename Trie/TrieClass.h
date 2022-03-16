#include "TrieNode.h"
#include <string>

class Trie {

    TrieNode *root;

    public:
    Trie() {
        root = new TrieNode('\0');
    }

    ~Trie() {
        delete root;
    }

    void insert(TrieNode* root, string word) {
        if (word.empty()) {
            root -> isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode* child;
        if (root -> children[index] != NULL) {
            child = root -> children[index];
        } else {
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }
        insert(child, word.substr(1));
    }

    void insert(string word) {
        insert(root, word);
    }

    bool exists(TrieNode* root, string word) {
        if (word.empty()) return root -> isTerminal;

        int index = word[0] - 'a';
        
        if (root -> children[index] != NULL) {
            return exists(root -> children[index], word.substr(1));
        } else return false;
    }

    bool exists(string word) {
        return exists(root, word);
    }

    void remove(TrieNode* root, string word) {
        if (word.empty()) {
            root -> isTerminal = false;
            return;
        }
        TrieNode* child;
        int index = word[0] - 'a';
        if (root -> children[index] != NULL) {
            child = root -> children[index];
        } else return;
        remove(child, word.substr(1));
        if (child -> isTerminal == false) {
            for (int i = 0 ; i < 26 ; i ++) {
                if (child -> children[i] != NULL) return;
            }
            delete child;
        }
    }

    void remove(string word) {
        remove(root, word);
    }
};
