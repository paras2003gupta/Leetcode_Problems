class Solution {
public:
    bool isValid(int nx, int ny, int n , int m){
        if(nx>=0&&nx<n&&ny>=0&&ny<m){
            return true;
        }
        return false;
    }
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int,int>>v = {{0,-1},{0,1},{-1,0},{1,0}};
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0] = 0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            int sz = pq.size();
            for(int i = 0;i<sz ; i++){
                auto tp = pq.top();
                pq.pop();
                int x = tp.second.first;
                int y = tp.second.second;
                int w = tp.first;
                if(w>dist[x][y])continue;
                for(int i = 0;i<4 ; i++){
                    int nx= x+v[i].first;
                    int ny = y+v[i].second;
                    if(isValid(nx,ny,n,m)&&w+grid[nx][ny]<dist[nx][ny]){
                        dist[nx][ny] = w+grid[nx][ny];
                        pq.push({dist[nx][ny],{nx,ny}});
                    }
                }


            }

        }
        return dist[n-1][m-1];
    }
};