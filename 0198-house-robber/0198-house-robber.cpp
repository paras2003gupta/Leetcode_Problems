class Solution {
    private:
    int memoisationrob(vector<int>nums,vector<int>&dp,int i){
        if(i==0){
            return dp[0]= nums[0];
        }
        if(i<0)return 0;

        if(dp[i]!=-1)return dp[i];

        int take = memoisationrob(nums,dp,i-2)+nums[i];
        int nottake = memoisationrob(nums,dp,i-1);
        
        return  dp[i]=max(take,nottake);
    }
public:
    int rob(vector<int>& nums) {
        int prev = nums[0];
        int prevprev = 0;
        for(int i =1 ; i<nums.size() ; i++){
            int take = nums[i]+prevprev;
            int nottake = prev;
            int curr = max(take,nottake);
            prevprev = prev;
            prev = curr;
        }
        vector<int>dp(nums.size()+1,-1);

        return memoisationrob(nums,dp,nums.size()-1);
    }
};