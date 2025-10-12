class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       vector<pair<int,int>>adj[n];

        for(auto it:flights){
            int u = it[0];
            int v  = it[1];
            int wt = it[2];

            adj[u].push_back({v,wt});

        }
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        vector<int>distTo(n,INT_MAX);
        distTo[src] = 0;
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int stops = front.first;
            int node = front.second.first;
            int dist = front.second.second;
            for(auto nbr:adj[node]){
                int v = nbr.first;
                int wt = nbr.second;
                int newcost= dist+wt;
                if(newcost<distTo[v]&&stops<=k){
                    distTo[v] = newcost;
                    q.push({stops+1,{v,distTo[v]}});
                }
            }
        }
        return (distTo[dst]==INT_MAX)?-1:distTo[dst];

    }
};