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


        map<int,map<int,multiset<int>>>mp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto front  = q.front();
            q.pop();

            TreeNode* nd = front.first;;
            int x = front.second.first;
            int y = front.second.second;

            mp[x][y].insert(nd->val);

            if(nd->left){
                q.push({nd->left,{x-1,y+1}});
            }
            if(nd->right){
                q.push({nd->right,{x+1,y+1}});
            }


        }
        vector<vector<int>>ans;
        for(auto it:mp){
            vector<int>col;
            for(auto j:it.second){
                col.insert(col.end(),j.second.begin(),j.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};