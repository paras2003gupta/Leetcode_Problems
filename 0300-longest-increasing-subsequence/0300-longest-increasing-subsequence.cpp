class Solution {
    private:
    int solve(vector<int>&nums,int i,int prev,vector<vector<int>>&dp){
        if(i==nums.size()){
            return 0;
        }
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];

        int len = solve(nums,i+1,prev,dp);

        if(prev==-1||nums[i]>nums[prev]){
            len = max(len,1+solve(nums,i+1,i,dp));
        }
        return dp[i][prev+1]= len;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));
        return solve(nums,0,-1,dp);
    }
};