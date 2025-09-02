class Solution {
public:
    vector<vector<int>>ans;
    void dfs(int node, int target,  vector<int>adj[],vector<int>&res){
        if(node==target){
            res.push_back(target);
            ans.push_back(res);
            res.pop_back();
            return;
        }
        for(auto it:adj[node]){
            res.push_back(node);
            dfs(it,target,adj,res);
            res.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
       vector<int>adj[n];
       for(int i = 0;i<n ; i++){
            for(auto it:graph[i]){
                adj[i].push_back(it);
            }
       }
       vector<int>res;
       dfs(0,n-1,adj,res);
       return ans;
    }
};