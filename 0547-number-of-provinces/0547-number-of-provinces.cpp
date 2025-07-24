class Solution {
    private:
    void dfs(int &cnt,vector<int>&visited,vector<vector<int>>&adj,int node){
        visited[node] = 1;
        for(auto it:adj[node]){
            if(!visited[it]){
                visited[it] = 1;
                dfs(cnt,visited,adj,it);
            }
        }
        return;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>>adj(n);
        int m = isConnected[0].size();
        for(int i = 0; i<n ; i++){
            for(int j = 0; j<m ; j++){
                if(isConnected[i][j]==1&&i!=j){
                    adj[i].push_back(j);
                }
            }
        }

        int cnt = 0;
        vector<int>visited(n,0);
        for(int i = 0; i<adj.size() ; i++){
            if(!visited[i]){
                cnt++;
                dfs(cnt,visited,adj,i);
            }
        }
        return cnt;


        
    }
};