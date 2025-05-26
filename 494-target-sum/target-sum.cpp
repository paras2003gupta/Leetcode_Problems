class Solution {
    private:
    int solve(vector<int>&nums,int target){
        int tot = 0;
        int n = nums.size();
        for(auto it:nums){
            tot+=it;
        }
        if((target+tot)%2!=0||target+tot<0){
            return 0;
        }
        target = (target+tot)/2;
        vector<vector<int>>dp(n,vector<int>(target+1,0));
        dp[0][0]=1;
        if(nums[0]==0){
            dp[0][0]=2;
        }
        if(nums[0]!=0&&nums[0]<=target){
            dp[0][nums[0]]=1;
        }
        for(int i = 1 ;i<n ; i++){
            for(int j = 0; j<target+1 ; j++){
                int nottake = dp[i-1][j];
                int take = 0;
                if(j>=nums[i]){
                    take = dp[i-1][j-nums[i]];
                }
                dp[i][j] = take+nottake;
            }
        }
        return dp[n-1][target];

        
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // this question is basically select two subsets whose difference is target;

        return solve(nums,target);
    }
};