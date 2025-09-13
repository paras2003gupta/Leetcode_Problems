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
    int count_nodes(TreeNode * root){
        if(root==NULL){
            return 0;
        }

        int lc = count_nodes(root->left);
        int rc = count_nodes(root->right);

        return lc+rc+1;
    }
    bool dfs(int n , TreeNode* root, int i){
        
        if(root==NULL){
            return true;
        }
        //i commited a mistake i write this i>n before null this will give error because it will count NULL value as node and that will not be a node so that will give me the error. if i debug it self this will be beneficial for me but no problem ............m happy :)
        if(i>n){
            return false;
        }
        bool la = dfs(n,root->left,2*i);
        bool ra  = dfs(n,root->right,2*i+1);
        return la&&ra;
    }
    // By DFS method Previous one was using BFS method....
    bool isCompleteTree(TreeNode* root) {
        int totalNodes = count_nodes(root);


        return dfs(totalNodes,root,1);

    }
};