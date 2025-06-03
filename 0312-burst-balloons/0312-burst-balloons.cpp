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
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(nums,1,n-2,dp);

    }
};