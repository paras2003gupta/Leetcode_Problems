class Solution {
public:
    void dfs(vector<int>&visited,vector<vector<int>>adj , int *v , int *e,int node){
        visited[node]=1;
        (*v)++;
        (*e) += adj[node].size();
        for(auto it:adj[node]){
            if(!visited[it]){
                dfs(visited,adj,v,e,it);
            }
        }
        return;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>visited(n,0);
        vector<vector<int>>adj(n);
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt = 0;
        for(int i =0 ; i< n ;i++){
            if(!visited[i]){
                int v = 0,e=0;
                dfs(visited,adj,&v,&e,i);
                e = e/2;
                if(e == (v*(v-1))/2){
                    cnt++;
                }
            }
        }
        return cnt;

    }
};