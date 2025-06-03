class Solution {
public:
    int solve(vector<int>&arr,int i , int j,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int maxi = INT_MIN;
        for(int ind  = i ; ind<= j ; ind++ ){
            

            maxi = max(maxi,arr[i-1]*arr[ind]*arr[j+1]+solve(arr,i,ind-1,dp)+solve(arr,ind+1,j,dp));
        }
        return dp[i][j]= maxi;
    }
    int solveTab(vector<int>&nums){
        int n = nums.size();
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));

        for(int i = n-2;i>=1 ; i--){
            for(int j = 1 ; j<=n-2 ; j++){
                if(i>j)continue;
                int maxi = INT_MIN;
                for(int ind  = i ; ind<= j ; ind++ ){
                    

                    maxi = max(maxi,nums[i-1]*nums[ind]*nums[j+1]+dp[i][ind-1]+dp[ind+1][j]);
                }

                dp[i][j] = maxi;
            }
        }
        return dp[1][n-2];
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solveTab(nums);
        return solve(nums,1,n-2,dp);

    }
};