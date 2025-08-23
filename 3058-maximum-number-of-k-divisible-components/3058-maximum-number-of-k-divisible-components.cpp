class Solution {
public:
    long long compo = 0;
    long long dfs(int node , vector<int>adj[], vector<int>&values,int k,vector<int>&visited){
        long long sum = values[node];
        visited[node] = 1;
        for(auto it: adj[node]){
            if(!visited[it]){
                sum+=1LL*dfs(it,adj,values,k,visited);
            }
        }

        if(sum%k==0){
            compo++;
            return 0;
        }
        return sum;
    


    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<int>adj[n];
        for(auto it:edges){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>visited(n,0);
        for(int i = 0;i<n ;i++){
            if(!visited[i]) dfs(i,adj,values,k,visited);
            
        }
        return compo;
        

    }
};