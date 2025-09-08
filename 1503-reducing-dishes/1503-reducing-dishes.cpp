class Solution {
public:
    int solve(vector<int>&s, int time,int i,vector<vector<int>>&dp){
        if(i==s.size()){
            return 0;
        }
        if(dp[i][time]!=-1){
            return dp[i][time];
        }
        int ans=  INT_MIN;

        ans = max(ans,time*s[i]+solve(s,time+1,i+1,dp));

        ans = max(ans,solve(s,time,i+1,dp));
        return dp[i][time]= ans;
    }
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(),s.end());
        vector<vector<int>>dp(s.size()+2,vector<int>(s.size()+2,-1));
        int ans = solve(s,1,0,dp);
        return ans;
    }
};