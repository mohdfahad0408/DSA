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
struct Data{
    bool isBST;
    int minVal;
    int maxVal;
    int sum;
};

    Data calc(TreeNode* root,int &c){
        if(nullptr==root)return {true,INT_MAX,INT_MIN,0};
         
         Data l=calc(root->left , c);
         Data r=calc(root->right , c);

         if(l.isBST && r.isBST && l.maxVal < root->val && root->val < r.minVal){
            int sum=l.sum + root->val + r.sum;
            c=max(c,sum);
            int minVal = min(root->val, l.minVal);
            int maxVal = max(root->val, r.maxVal);

            return {true,minVal,maxVal,sum};
         }
         return {false,0,0,0};
    }

   
    int maxSumBST(TreeNode* root) {
        int c=0;
        calc(root,c);
        return c;
    }
};