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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>>mp;

        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});

        while(!q.empty()){
            
            auto top = q.front();
            q.pop();

            TreeNode* node=  top.first;
            int x = top.second.first;
            int y = top.second.second;
            mp[x][y].push_back(node->val);
            if(node->left){
                q.push({node->left,{x-1,y+1}});
            }
            if(node->right){
                 q.push({node->right,{x+1,y+1}});
            }



        }
        vector<vector<int>>ans;
        for (auto &p : mp) {
        vector<int> col;
        for (auto &q : p.second) {
            auto vals = q.second;
            sort(vals.begin(), vals.end()); // sort if multiple nodes at same position
            for (int v : vals) col.push_back(v);
        }
        ans.push_back(col);
        }
        return ans;
    }
};