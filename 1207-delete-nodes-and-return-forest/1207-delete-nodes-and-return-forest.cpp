#include <vector>
#include <unordered_set>
#include <map>
using namespace std;

/**
 * Definition for a binary tree node.
 */


class Solution {
private:
    TreeNode* solve(TreeNode* root, unordered_set<int>& to_delete, vector<TreeNode*>& ans) {
        if (root == NULL) {
            return NULL;
        }
        root->left = solve(root->left, to_delete, ans);
        root->right = solve(root->right, to_delete, ans);
        if (to_delete.find(root->val) != to_delete.end()) {
            if (root->left) {
                ans.push_back(root->left);
            }
            if (root->right) {
                ans.push_back(root->right);
            }
            delete root;  // Free the memory of the deleted node
            return NULL;
        }
        return root;
    }

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> delete_set(to_delete.begin(), to_delete.end());
        vector<TreeNode*> ans;
        root = solve(root, delete_set, ans);
        if (root) {  // If the root itself is not deleted, add it to the result
            ans.push_back(root);
        }
        return ans;
    }
};
