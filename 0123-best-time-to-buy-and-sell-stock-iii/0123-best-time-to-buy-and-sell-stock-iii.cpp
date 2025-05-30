class Solution {
    private:
    int solve(vector<int>&prices, int i , int buy, int cap,vector<vector<vector<int>>>&dp){
        if(cap==0||i==prices.size())return 0;
        if(dp[i][buy][cap]!=-1)return dp[i][buy][cap];
        if(buy){
            int b = -prices[i] + solve(prices,i+1,0,cap,dp);
            int nb = solve(prices,i+1,1,cap,dp);
            return dp[i][buy][cap]= max(nb,b);
        }
        else{
            int s = prices[i] + solve(prices,i+1,1,cap-1,dp);
            int ns = solve(prices,i+1,0,cap,dp);
            return dp[i][buy][cap]= max(s,ns);
        }

    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(prices,0,1,2,dp);
    }
};