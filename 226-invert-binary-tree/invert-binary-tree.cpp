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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL||(root->left==NULL&&root->right==NULL))return root;
        TreeNode* dummyRight=NULL;
        TreeNode* dummyLeft =NULL;
        dummyRight=  invertTree(root->left);
        dummyLeft = invertTree(root->right);
        
        root->left = dummyLeft;
        root->right = dummyRight;
        return root;


    }
};