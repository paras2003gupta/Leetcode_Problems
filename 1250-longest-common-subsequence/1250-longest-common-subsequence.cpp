class Solution {
    private:
    int solve(string& s, string& k , int n , int m, vector<vector<int>>& dp){
    if(n == 0 || m == 0){
        return 0;
    }
    if(dp[n][m] != -1){
        return dp[n][m];
    }

    if(s[n - 1] == k[m - 1]){
        return dp[n][m] = 1 + solve(s, k, n - 1, m - 1, dp);
    }
    else{
        return dp[n][m] = max(solve(s, k, n - 1, m, dp), solve(s, k, n, m - 1, dp));
    }
}

public:
   int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return solve(text1, text2, n, m, dp);
}

};