class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        // Precompute palindrome substrings
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                if (len == 1) {
                    isPal[i][j] = true;
                } else if (len == 2) {
                    isPal[i][j] = (s[i] == s[j]);
                } else {
                    isPal[i][j] = (s[i] == s[j]) && isPal[i+1][j-1];
                }
            }
        }

        // dp[i] = min cuts for s[i..n-1]
        vector<int> dp(n+1, 0);
        dp[n] = -1; // base case: no cut needed after the end

        for (int i = n-1; i >= 0; --i) {
            int mini = INT_MAX;
            for (int j = i; j < n; ++j) {
                if (isPal[i][j]) {
                    mini = min(mini, 1 + dp[j+1]);
                }
            }
            dp[i] = mini;
        }
        return dp[0];
    }
};
