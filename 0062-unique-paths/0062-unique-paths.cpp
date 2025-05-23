class Solution {
    private:
    int solve(int i , int j , vector<vector<int>>&dp){
        if(i==0&&j==0){
            return dp[0][0]=1;
        }
        if(i<0||j<0){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans = solve(i,j-1,dp)+solve(i-1,j,dp);
        return dp[i][j] = ans;
    }
    int solveTab(int m , int n){
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i = 0;i<m ; i++){
            for(int j = 0 ; j< n; j++){
                if(i==0&&j==0) dp[i][j] =1;
                else{
                    int up = 0;
                    int left = 0;
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];

                    dp[i][j] = up+left;
                }
                
            }
        }
        return dp[m-1][n-1];
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solveTab(m,n);
    }
};