class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<set<int>>ans(n,set<int>());
        vector<vector<int>>adj(n,vector<int>());
        vector<int>innode(n,0);
        queue<int>q;
        for(int i = 0;i<edges.size() ;i++){
            int u = edges[i][0];
            int v=  edges[i][1];
            innode[v]++;
            adj[u].push_back(v);
        }
            for(int i = 0; i < n; i++) {
                if(innode[i] == 0) {
                    q.push(i);
                }
            }
        while(!q.empty()){
            int node = q.front();
            q.pop();
                for(auto it:adj[node]){
                ans[it].insert(node);
                for(auto k:ans[node]){
                    ans[it].insert(k);
                }
                innode[it]--;             // reduce indegree
                if(innode[it] == 0) {     // push only when ready
                    q.push(it);
                }
    }

        }
        vector<vector<int>>s;
        for(auto &it:ans){
            vector<int>v;
            for(auto t=it.begin(); t!=it.end() ; t++){
                v.push_back(*t);
            }
            s.push_back(v);
        }
        return s;




    }
};