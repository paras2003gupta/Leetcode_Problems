/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public: 
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root==p||root==q){
            return root;
       }
       if(root==NULL){
        return NULL;
       }

       TreeNode* la= lowestCommonAncestor(root->left,p,q);
       TreeNode* ra= lowestCommonAncestor(root->right,p,q);

        if(la==NULL&&ra==NULL)return NULL;
        if(la==NULL)return ra;
        if(ra==NULL)return la;
        return root;

    }
};