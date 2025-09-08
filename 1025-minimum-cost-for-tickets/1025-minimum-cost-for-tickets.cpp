class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs,  int i, vector<int>& dp){
        if(i >= days.size()) return 0;
        if(dp[i]!=-1)return dp[i];
        int ans = INT_MAX;
        
    
            // 1-day pass
            ans = min(ans, costs[0] + solve(days, costs, i+1, dp));
            // 7-day pass
            int max_day = days[i]+6;
            int j = i;
            while(j<days.size()&&days[j]<=max_day){
                j++;
            }
            ans = min(ans, costs[1] + solve(days, costs, j, dp));
            // 30-day pass
            j = i;
            max_day = days[i]+29;
            while(j<days.size()&&days[j]<=max_day){
                j++;
            }
            ans = min(ans, costs[2] + solve(days, costs,  j, dp));
        
        return dp[i]= ans;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n,-1); 
        // 400 is safe since max day is <= 365
        return solve(days, costs,  0, dp);
    }
};
