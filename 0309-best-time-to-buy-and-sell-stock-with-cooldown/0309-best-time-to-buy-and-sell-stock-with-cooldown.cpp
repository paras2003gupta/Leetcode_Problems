class Solution {
public:
    int solve(int i , vector<int>& prices,bool canBuy,vector<vector<int>>&dp){
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][canBuy]!=-1)return dp[i][canBuy];
        int maxpro = INT_MIN;
        if(canBuy){
            maxpro = -prices[i]+max(maxpro,solve(i+1,prices,0,dp));
            maxpro = 0+max(maxpro,solve(i+1,prices,1,dp));
        }
        else{
            maxpro = +prices[i]+max(maxpro,solve(i+2,prices,1,dp));
            maxpro = max(maxpro,solve(i+1,prices,0,dp));
        }

        return dp[i][canBuy] =  maxpro;


    }
    int maxProfit(vector<int>& prices) {
        //1->buy allowed;
        //0 = sell allowed
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        int ans  = solve(0,prices,1,dp);
        return ans;
    }
};