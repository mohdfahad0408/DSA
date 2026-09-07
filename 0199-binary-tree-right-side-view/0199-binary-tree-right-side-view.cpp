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

    void lastLevel(TreeNode* root,int lvl,vector<int>&ans){
        if(nullptr==root)return ;
        ans[lvl]=root->val;
        lastLevel(root->left,lvl+1,ans);
        lastLevel(root->right,lvl+1,ans);
    }
    int level(TreeNode* root){
        if(nullptr==root)return 0;
        return max(level(root->left),level(root->right))+1;
    }

    vector<int> rightSideView(TreeNode* root) {
        int n=level(root);
        vector<int>ans(n,0);
        lastLevel(root,0,ans);
        return ans;
    }
};