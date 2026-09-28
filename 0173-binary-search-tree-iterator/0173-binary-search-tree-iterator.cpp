/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:

    TreeNode* root;
    vector<int> inorder;
    int i;
    BSTIterator(TreeNode* root) {
        this->root=root;
        i=0;
        getTree(root);
    }

    void getTree(TreeNode* temp){
        if(temp==nullptr) return ;
        getTree(temp->left);
        inorder.push_back(temp->val);
        getTree(temp->right);
    }
    
    int next() {
        return inorder[i++];
    }
    
    bool hasNext() {
        return i<inorder.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */