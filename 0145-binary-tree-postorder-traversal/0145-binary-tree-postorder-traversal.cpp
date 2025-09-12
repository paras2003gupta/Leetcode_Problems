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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>st1,st2;
        if(root==NULL){
            return ans;
        }
        st1.push(root);

        while(!st1.empty()){
            auto top = st1.top();
            st1.pop();

            if(top->left!=NULL)st1.push(top->left);
            if(top->right!=NULL)st1.push(top->right);

            st2.push(top);
        }
        while(!st2.empty()){
            auto top = st2.top();
            st2.pop();
            ans.push_back(top->val);
        }
        return ans;

    }
};