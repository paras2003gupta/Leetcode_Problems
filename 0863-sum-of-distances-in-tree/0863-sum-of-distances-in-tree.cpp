class Solution {
public:
    long long root_res;//global variable 
    void dfs_first(vector<int>adj[],vector<int>&child_cnt,int node,int par,int depth){
        int cnt = 1;
        root_res+=depth;//calculating dist of each node from 0..
        for(auto it:adj[node]){
            if(it!=par){
                dfs_first(adj,child_cnt,it,node,depth+1);
                cnt+=child_cnt[it];
            }
        }
        child_cnt[node] = cnt;
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {

        //created dist array which stores dist of node i from all other nodes.
        vector<int>dist(n,0);
        //child_of_child array stores the no of child of node i including itself.
        vector<int>child_of_child(n,0);
        //this is normal adjacency list.
        vector<int>adj[n];
        //creating adjacency list.
        for(int i = 0;i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //root_res will store dist of root node from each node that will be calculated in our dfs_first call.
        root_res = 0;
        //dfs_first call will do dfs and calculate result of root_res and child_of_child vector.
        dfs_first(adj,child_of_child,0,-1,0);
        //this bfs call calculate result of whole dist vector by using child_of_child and dist[root] thing.
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