class Solution {
public:
    long long root_res;
    void dfs_first(vector<int>adj[],vector<int>&child_cnt,int node,int par,int depth){
        int cnt = 1;
        root_res+=depth;
        for(auto it:adj[node]){
            if(it!=par){
                dfs_first(adj,child_cnt,it,node,depth+1);
                cnt+=child_cnt[it];
            }
        }
        child_cnt[node] = cnt;
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int>dist(n,0);
        vector<int>child_of_child(n,0);
        vector<int>adj[n];
        for(int i = 0;i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        root_res = 0;
        dfs_first(adj,child_of_child,0,-1,0);
        queue<int>q;
        q.push(0);
        dist[0] = root_res;
        vector<int>visited(n,0);
        visited[0] = 1;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0;i<sz ; i++){
                int top = q.front();
                visited[top]=1;
                q.pop();

                for(auto it:adj[top]){
                    if(!visited[it]){
                        dist[it] = dist[top]-2*child_of_child[it]+n;
                        q.push(it);
                    }
                    
                    
                }
            }
        }       
        return dist;
    
    }
};