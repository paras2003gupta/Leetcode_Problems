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
    pair<bool,int> dfs(TreeNode* root){
        if(root==NULL){
            return {true,0};
        }

        auto lh = dfs(root->left);
        auto rh = dfs(root->right);


        if(!lh.first||!rh.first)return {false,0};
        if(abs(lh.second-rh.second)<=1){
            //its fine;...
            return {true,1+max(lh.second,rh.second)};
        }
        return {false,0};

        
    }

    bool isBalanced(TreeNode* root) {
        pair<bool,int> ans = dfs(root);
        return ans.first;
    }
};