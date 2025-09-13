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
    int pastNullNodeSeen = false;

    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* frontNode = q.front();
            q.pop();
            if(frontNode==NULL){
                pastNullNodeSeen = true;
                continue;
            }
            else{
                if(pastNullNodeSeen==true){
                    return false;
                }
                q.push(frontNode->left);
                q.push(frontNode->right);
            }
        }
        return true;
    }
};