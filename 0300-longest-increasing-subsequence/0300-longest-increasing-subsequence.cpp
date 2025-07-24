class Solution {
    private:
    int solve(vector<int>&nums,int i,int prev,vector<vector<int>>&dp){

        if(i==nums.size()){ 
            return 0;
        }
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        int take = INT_MIN;
        if(prev==-1||nums[prev]<nums[i]){
            take = 1+solve(nums,i+1,i,dp);
        }
        int nottake = solve(nums,i+1,prev,dp);
        return dp[i][prev+1]= max(take,nottake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+2,-1));
        return solve(nums,0,-1,dp);
    }
};