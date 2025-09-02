class Solution {
public:
    vector<vector<int>>ans;
    void dfs(int node, int target,  vector<int>adj[],vector<int>&res){
        res.push_back(node);
        if(node==target){
            ans.push_back(res);
        }
        for(auto it:adj[node]){
           dfs(it,target,adj,res);
        }
        res.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
       vector<int>adj[n];
       for(int i = 0;i<n ; i++){
            for(auto it:graph[i]){
                adj[i].push_back(it);
            }
       }
       //maintained a res vector which will store our calls and after call pop back the answer..
       vector<int>res;
       dfs(0,n-1,adj,res);
       return ans;
    }
};