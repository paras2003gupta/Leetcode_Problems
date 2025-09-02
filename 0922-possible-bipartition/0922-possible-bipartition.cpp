class Solution {
public:
   


    bool dfs(int node, vector<int>&color,vector<int>adj[],int c,int par){
        color[node] = c;

        for(auto it:adj[node]){
            if(color[it]==-1){
                if(!dfs(it,color,adj,!c,node))return false;
            }
            else if(color[it]==color[node]){
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>adj[n+1];
        for(int i = 0;i<dislikes.size() ; i++){
            int u = dislikes[i][0];
            int v = dislikes[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>color(n+1,-1);
        for(int i= 1;i<=n ; i++){
            if(color[i]==-1){
                if(!dfs(i,color,adj,0,0)) return false;
            }
            
        }
        return true;
    }
};