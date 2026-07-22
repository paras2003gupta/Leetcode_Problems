class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();


        queue<pair<int,int>>q;
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i= 0 ; i< m ; i++){
            if(board[i][0] =='O' &&!visited[i][0]){
                q.push({i,0});
                visited[i][0]=1;
            }
            if(board[i][n-1]=='O'&&!visited[i][n-1]){
                q.push({i,n-1});
                visited[i][n-1]=1;
            }
        }
        for(int i= 0 ; i< n ; i++){
            if(board[0][i] =='O' &&!visited[0][i]){
                q.push({0,i});
                visited[0][i]=1;
            }
            if(board[m-1][i]=='O'&&!visited[m-1][i]){
                q.push({m-1,i});
                visited[m-1][i]=1;
            }
        }
        int dx[] = {0,0,1,-1};
        int itr=0;
        int dy[] = {1,-1,0,0};
        while(!q.empty()){
            
            int sz = q.size();

            for(int i  =0;i< sz ; i++){
                auto it = q.front();
                q.pop();
                cout<<it.first<<" "<<it.second<<" "<<itr<<" "<<endl;
                int x = it.first;
                int y = it.second;

                for(int j= 0;j<4 ; j++){
                    int nr = x+dx[j];
                    int ny  = y+dy[j];

                    if(nr>=0&&nr<m && ny>=0 && ny<n && !visited[nr][ny]&&board[nr][ny]=='O'){
                        q.push({nr,ny});
                        visited[nr][ny]=1;
                    }
                }
            }
            itr++;
        }
        for(auto it:visited){{
            for(auto j:it){
                cout<<j<<" ";
            }cout<<endl;
        }}
        for(int i =0;i<m;i++){
            for(int j = 0;j<n ; j++){
                if(board[i][j]=='O'&& visited[i][j]==0) board[i][j]='X';
            }
        }
        return;

    }
};