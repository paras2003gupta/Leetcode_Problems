class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>dist(n,vector<int>(n,1e9));

        if(grid[0][0]==1)return -1;

        dist[0][0] = 1;
        if(n==1){
            return dist[0][0];
        }
        queue<pair<int,int>>q;
        q.push({0,0});
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = -1;i<=1; i++){
                for(int j =-1 ; j<=1 ; j++){
                    if(i==0&&j==0)continue;
                    int nx = x+i;
                    int ny = y+j;
                    if(nx==n-1&&ny==n-1&&grid[nx][ny]==0)return 1+dist[x][y];
                    if(nx>=0&&nx<n&&ny>=0&&ny<n&&grid[nx][ny]==0&&dist[nx][ny]>dist[x][y]+1){
                        dist[nx][ny]=1+dist[x][y];
                        q.push({nx,ny});
                    }
                    
                }
            }

        }
        









        return -1;
    }
};