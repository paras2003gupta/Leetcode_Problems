class Solution {
    private:
    int solve(string s, string t,int n,int m){
        if(n<0||m<0){
            return 0;
        }
        if(s[n]==t[m]){
            return 1+solve(s,t,n-1,m-1);
        }else{
            return max(solve(s,t,n-1,m),solve(s,t,n,m-1));
        }
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i= 1 ;i<=n ; i++){
            for(int j =1 ; j<=m ; j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        int t = dp[n][m];
        return word1.size()+word2.size()-(2*t);
    }
};