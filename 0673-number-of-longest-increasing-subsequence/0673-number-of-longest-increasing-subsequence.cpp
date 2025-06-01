class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return 1;
        int maxi = INT_MIN;
        vector<int>dp(n,1),cnt(n,1);
        for(int i = 0;i<n ; i++){
            for(int j = 0 ; j< i ; j++){
                if(nums[j]<nums[i]&&dp[i]<1+dp[j]){
                    dp[i] = 1+dp[j];
                    //inherit 
                    cnt[i] = cnt[j];
                }else if(nums[i]>nums[j]&&dp[i]==1+dp[j]){
                    //increase count
                    cnt[i]+=cnt[j];
                }
                maxi = max(maxi,dp[i]);
            }
        }
        int ans =0;
        for(int i = 0;i<n ; i++){
            if(dp[i]==maxi){
                ans+= cnt[i];
            }
        }
        return ans;
    }
};