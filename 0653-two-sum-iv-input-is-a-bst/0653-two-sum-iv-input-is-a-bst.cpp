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
stack<TreeNode*>st;
bool reverse=true;

    BSTIterator(TreeNode* root,bool isReversed) {
        reverse=isReversed;
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp=st.top();
        st.pop();
        if(!reverse)pushAll(temp->right);
        else (pushAll(temp->left));
        return temp->val;
        
    }
    
    bool hasNext() {
        return st.size()!=0;
    }
private:

    void pushAll(TreeNode* node) {
        while(node != nullptr) {
            st.push(node);
            if(reverse) node = node->right;
            else node = node->left;
        }
    }
    
};
class Solution{
    public:
    bool findTarget(TreeNode* root, int k) {
        if(nullptr==root) return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i=l.next();
        int j=r.next();

        while(i<j){
            if(i+j==k) return true;
            if(i+j>k)j=r.next();
            else i=l.next();
        }
        return false;
    }
};