class Solution {
public:
    int solve(vector<int>&arr,int k , int i,vector<int>&dp){
        if(i==arr.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int len = 0,maxi = INT_MIN;
        int n = arr.size();
        int sum = INT_MIN;
        for(int j = i;j<min(n,i+k) ; j++){
            len++;
            maxi = max(maxi,arr[j]);
            sum = max(sum,len*maxi+solve(arr,k,j+1,dp));
        }
        return dp[i]= sum;

    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {\
        vector<int>dp(arr.size()+1,-1);
        return solve(arr,k,0,dp);
    }
};