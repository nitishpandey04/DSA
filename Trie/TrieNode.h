
class TrieNode {

    public:
    char data;
    TrieNode* *children;
    bool isTerminal;

    TrieNode(char d) {
        data = d;
        children = new TrieNode*[26];
        for (int i = 0 ; i < 26 ; i ++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }

    ~TrieNode() {
        for (int i = 0 ; i < 26 ; i ++) {
            TrieNode* child = children[i];
            delete child;
        }
        delete [] children;
    }
};
