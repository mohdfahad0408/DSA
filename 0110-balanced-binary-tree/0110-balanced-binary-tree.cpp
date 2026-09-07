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
class Solution {
public:


    int level(TreeNode* root){
        if(nullptr==root)return 0;
        int l=level(root->left);
        int r=level(root->right);
        return max(l,r)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(nullptr==root)return true;
        int LL=level(root->left);
        int RL=level(root->right);
        if(abs(LL-RL)>1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};