class Solution {
public:
    int solve(string &text1, string &text2, int i , int j,vector<vector<int>>&dp){
        if(i<0||j<0){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int ans = INT_MIN;
        
        ans = max(solve(text1,text2,i-1,j,dp),ans);
        ans = max(solve(text1,text2,i,j-1,dp),ans);
        if(text1[i]==text2[j]){
            ans =  max(1+solve(text1,text2,i-1,j-1,dp),ans);
        }
        return dp[i][j]= ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        vector<vector<int>>dp1(n+1,vector<int>(m+1,0));

        for(int i = 1 ; i<= n ; i++){
            for(int j = 1; j<=m ; j++){
                if(text1[i-1]==text2[j-1]){
                    dp1[i][j] = 1+dp1[i-1][j-1];
                }
                else{
                    dp1[i][j] = max(dp1[i-1][j], dp1[i][j-1]);
                }
            }
        }
        return dp1[n][m];
        int ans =  solve(text1,text2,text1.size()-1,text2.size()-1,dp);
        return ans==INT_MIN?0:ans;
    }
};