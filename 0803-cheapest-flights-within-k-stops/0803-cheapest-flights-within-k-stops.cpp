class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int,int>>pq;
        pq.push({0,src});
        vector<int>dist(n,INT_MAX);
        dist[src] = 0;
        vector<vector<pair<int,int>>>adj(n,vector<pair<int,int>>());
        for(int i = 0;i<flights.size() ; i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];

            adj[u].push_back({v,w});
        }
        int steps = 0;
        while(!pq.empty()){
            int sz = pq.size();
            steps++;
            for(int i = 0;i<sz ; i++){
                auto tp = pq.front();
                pq.pop();

                int w = tp.first;
                int u = tp.second;

                for(auto it:adj[u]){
                    int v = it.first;
                    int wt = it.second;
                    if(dist[v]>w+wt){
                        dist[v] = w+wt;
                        pq.push({dist[v],v});
                    }
                }
            }
            if(steps>k){
                break;
            }
        }
        return (dist[dst]==INT_MAX)?-1:dist[dst];


    }
};