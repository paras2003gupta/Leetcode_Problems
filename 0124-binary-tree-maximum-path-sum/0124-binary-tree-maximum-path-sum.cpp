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
    int maxi = INT_MIN;
    int dfs(TreeNode* root){
        if(root==NULL){
            return 0;
        }

        int lm = dfs(root->left);
        int rm = dfs(root->right);

        int val = root->val;
        int ans = val+((lm>=0)?lm:0)+((rm>=0)?rm:0);
        maxi  =max(maxi,ans);
        return val+max({lm,rm,0});
    }
    int maxPathSum(TreeNode* root) {
        int ans = dfs(root);
        return max(ans,maxi);
    }
};