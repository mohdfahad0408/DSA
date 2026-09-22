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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(NULL==root)return {};
        vector<vector<int>>arr;
        queue<TreeNode*>q;
        int n=1;
        bool prevInverted=true;
        q.push(root);
        while(q.size()){
            vector<int>temp;
            for(int i=0;i<n;i++){
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                temp.push_back(q.front()->val);
                q.pop();
            }
            if(!prevInverted) reverse(temp.begin(),temp.end());
            prevInverted=!prevInverted;
            arr.push_back(temp);
            n=q.size();
        }
        return arr;
    }
};