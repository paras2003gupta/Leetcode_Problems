class Solution {
    private:
    int solve(string &s, string &k , int n , int m,vector<vector<int>>&dp){
        if(n<0||m<0){
            return 0;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }

        if(s[n]==k[m]){
            return dp[n][m]= 1+solve(s,k,n-1,m-1,dp);
        }
        else{
            return dp[n][m]= max(solve(s,k,n-1,m,dp),solve(s,k,n,m-1,dp));
        }
    }
    int solveTab(string &s, string &k){
        vector<vector<int>>dp(s.size()+1,vector<int>(k.size()+1,0));

        for(int i = 1 ;i<=s.size() ; i++){
            for(int j = 1; j<=k.size() ;j++){
                if(s[i-1]==k[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[s.size()][k.size()];
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solveTab(text1,text2);
        // return solve(text1,text2,text1.size()-1,text2.size()-1,dp);
    }
};