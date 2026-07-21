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
    int maxPathSum(TreeNode* root) {
        
        int maxMsum = INT_MIN;

        int h = Height(maxMsum,root);
        return max(h,maxMsum);

    }
    int Height(int& maxMsum,TreeNode* root){
        if(root==NULL)return 0;

        int ls = Height(maxMsum,root->left);
        int rs = Height(maxMsum,root->right);
        ls = max(0,ls);
        rs = max(0,rs);
        maxMsum = max(maxMsum,ls+rs+root->val);
        
        return root->val + max(ls,rs);
        
    }
};