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
    int ans=0;
    void smallest(TreeNode* root,int &c){
        if(root==nullptr)return;
        smallest(root->left,c);
        if(--c==0)ans=root->val;
        smallest(root->right,c);
    }
    int kthSmallest(TreeNode* root, int k) {
        int c=k;
        smallest(root,c);
        return ans;
    }
};