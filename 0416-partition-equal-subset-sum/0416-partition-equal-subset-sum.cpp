class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total=  accumulate(nums.begin(),nums.end(),0);
        if(total%2==1||total<0)return false;
        int target= total/2;
        vector<vector<int>>dp(n,vector<int>(total+1,0));
        for(int i = 0;i<n;i++){
            dp[i][0]=1;
        }
        if(dp[0][nums[0]]<=total){
            dp[0][nums[0]]=1;
        }
        for(int i =1 ; i< n ; i++){
            for(int tar = 1 ; tar<=total ; tar++){
                if(nums[i]<=tar){
                    dp[i][tar]=dp[i-1][tar-nums[i]]||dp[i-1][tar];
                }else{
                    dp[i][tar]=dp[i-1][tar];
                }
            }
        }
        return dp[n-1][target]==1;


    }
};