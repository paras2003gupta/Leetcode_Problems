class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs, int days_cov, int i, vector<vector<int>>& dp){
        if(i == days.size()) return 0;

        if(dp[i][days_cov] != -1) return dp[i][days_cov];

        int ans = INT_MAX;
        if(days_cov >= days[i]){
            ans = min(ans, solve(days, costs, days_cov, i+1, dp));
        }
        else{
            // 1-day pass
            ans = min(ans, costs[0] + solve(days, costs, days[i], i+1, dp));
            // 3-day pass
            ans = min(ans, costs[1] + solve(days, costs, days[i]  +6, i+1, dp));
            // 7-day pass
            ans = min(ans, costs[2] + solve(days, costs, days[i] + 29, i+1, dp));
        }
        return dp[i][days_cov] = ans;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<vector<int>> dp(n, vector<int>(400, -1)); 
        // 400 is safe since max day is <= 365
        return solve(days, costs, 0, 0, dp);
    }
};
