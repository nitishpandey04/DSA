#include <vector>
using namespace std;
template <typename T>

class TreeNode {
    
    public:
    T data;
    vector<TreeNode*> children; // implicitly, typename of children pointers will be same as parent

    TreeNode(T d) {
        data = d;
    } 

    ~TreeNode() {
        for (int i = 0 ; i < children.size() ; i ++) {
            delete children[i];
        }
    }
};