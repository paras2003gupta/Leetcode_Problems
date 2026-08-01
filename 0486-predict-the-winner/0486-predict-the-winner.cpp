class Solution {
    int solve(vector<int>&nums,int s , int e,int turn,vector<vector<vector<int>>>&dp){
        if(s==e){
            if(turn)return nums[s];
            else return 0;
        }
        if(dp[s][e][turn]!=INT_MIN)return dp[s][e][turn];
        if(turn){
            int firstone = nums[s]+solve(nums,s+1,e,!turn,dp);
            int lastone = nums[e]+solve(nums, s,e-1,!turn,dp);
            return dp[s][e][turn]= max(firstone,lastone);
        }
        else{
            //opponent turn
            int firstone = -nums[s]+solve(nums,s+1,e,!turn,dp);
            int lastone = -nums[e]+solve(nums,s,e-1,!turn,dp);
            return dp[s][e][turn]= min(firstone,lastone);
        }
        
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        vector<vector<vector<int>>>dp(nums.size(),vector<vector<int>>(nums.size(),vector<int>(2,INT_MIN)));
        int ans = solve(nums,0,nums.size()-1,1,dp);
        if(ans>=0)return true;
        return false;
    }
};