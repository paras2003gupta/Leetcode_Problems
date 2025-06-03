class Solution {
    private:
    int solve(vector<int>&arr,int i , int j,vector<vector<int>>&dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int mini  = INT_MAX;
        for(int ind = i ; ind <=j ; ind++){
            mini = min(mini,arr[j+1]-arr[i-1]+solve(arr,i,ind-1,dp)+solve(arr,ind+1,j,dp));
        }
        return dp[i][j]=mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        vector<int>modifiedCuts;
        modifiedCuts.push_back(0);
        for(int i = 0;i<cuts.size() ; i++){
            modifiedCuts.push_back(cuts[i]);
        }
        modifiedCuts.push_back(n);
        vector<vector<int>>dp(modifiedCuts.size()+2,vector<int>(modifiedCuts.size()+2,-1));
        return solve(modifiedCuts,1,modifiedCuts.size()-2,dp);

    }
};