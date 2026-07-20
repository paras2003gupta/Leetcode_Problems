class Solution {
public:
    int solve(int amount , vector<int>&coins,int i,vector<vector<int>>&dp){
        if(i==0){
            if(amount%coins[i]==0){
                return 1;
            }
            return 0;
        }
        if(dp[amount][i]!=-1)return dp[amount][i];
        

        int nottake = solve(amount,coins,i-1,dp);
        int take =0;
        if(amount>=coins[i]){
            take = solve(amount-coins[i],coins,i,dp);
        }
        return dp[amount][i]= take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(amount+1,vector<int>(coins.size(),-1));
        return solve(amount,coins,coins.size()-1,dp);
    }
};