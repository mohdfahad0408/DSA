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
    void inorder(TreeNode* root,vector<int>&arr){   
        if(root==nullptr)return ;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }

    void correct(TreeNode* root,int e1,int e2){
        if(root==nullptr)return ;
        if(root->val==e1)root->val=e2;
        else if(root->val==e2)root->val=e1;
        correct(root->left,e1,e2);
        correct(root->right,e1,e2);
    }
    void recoverTree(TreeNode* root) {
        vector<int>arr,cpy;
        inorder(root,arr);
        cpy=arr;
        sort(cpy.begin(),cpy.end());
        int i=0;
        while(arr[i]==cpy[i]) i++;
        correct(root,arr[i],cpy[i]);
    }
};