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
    private:
    int  dfs(TreeNode* root){
        if(root==NULL){
            return 0;
        }

        int lh = dfs(root->left);
        int rh = dfs(root->right);
        return 1+max(lh,rh);
    }
public:
    int maxDepth(TreeNode* root) {
        int h = 0;
        int height = dfs(root);
        return height;
    }
};