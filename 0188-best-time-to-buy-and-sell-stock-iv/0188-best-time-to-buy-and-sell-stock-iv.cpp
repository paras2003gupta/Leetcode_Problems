class Solution {
    private:
    int solve(vector<int>&prices,int ind , int buy , int cap, vector<vector<vector<int>>>&dp){
        //base case
        if(cap==0||ind ==prices.size()){
            return 0;
        }
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        int profit = 0;
        if(buy){
            int b = -prices[ind]+solve(prices,ind+1,0,cap,dp);
            int nb = solve(prices,ind+1,1,cap,dp);
            profit = max(nb,b);
        }
        else{
            int s = prices[ind]+solve(prices,ind+1,1,cap-1,dp);
            int ns = solve(prices,ind+1,0,cap,dp);
            profit = max(s,ns);
        }
        return dp[ind][buy][cap] = profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2,vector<int>(k+1,-1)));

        return solve(prices,0,1,k,dp);
    }
};