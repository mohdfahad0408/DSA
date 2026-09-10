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
    int getSum(TreeNode* root,int k){
        if(nullptr==root)return 0;
        if(root->left==nullptr && root->right == nullptr ) return k*10+root->val;
        return getSum(root->left,k*10+root->val)+getSum(root->right,k*10+root->val);

    }
    int sumNumbers(TreeNode* root) {
        return (getSum(root,0));
    }
};