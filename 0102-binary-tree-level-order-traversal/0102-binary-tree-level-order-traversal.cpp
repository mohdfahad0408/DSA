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
    int levels(TreeNode* root){
        if(nullptr==root)return 0;
        return max(levels(root->left),levels(root->right))+1;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr)return {};
        int n=levels(root);
        vector<vector<int>>ans (n,vector<int>(0));
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});

        while(q.size()){
            pair<TreeNode*,int> front=q.front();
            q.pop();
            TreeNode* node=front.first;
            int lvl=front.second;
            ans[lvl].push_back(node->val);
            if(node->left)q.push({node->left,lvl+1});
            if(node->right)q.push({node->right,lvl+1});
        }
        return ans;
    }
};