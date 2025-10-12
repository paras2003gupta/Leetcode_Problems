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
    bool helper(TreeNode* p,TreeNode* q){
        if(q==NULL&&p==NULL)return true;

        if(q==NULL||p==NULL)return false;

        return p->val==q->val&&(helper(p->left,q->right)&&helper(p->right,q->left));
    }
    bool isSymmetric(TreeNode* root) {
        
        if(root==NULL)return true;
        if(root->left==NULL&&root->right == NULL)return true;

        return helper(root->left, root->right);


    }
};