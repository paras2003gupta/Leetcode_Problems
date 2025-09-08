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
    int solveTab(vector<int>&s){
        vector<vector<int>>dp(501,vector<int>(501,INT_MIN));
        for(int i = 0 ; i<=s.size() ; i++){
            dp[i][0] = 0;
        }
        dp[0][1] =s[0];
        for(int i = 1;i<s.size() ; i++){
            for(int time=  1; time<=s.size() ; time++){
                long long include =  s[i]*time+1LL*dp[i-1][time-1];
                long long exclude = dp[i-1][time];
                dp[i][time] = max(include,exclude);
            }
        }
        int ans= 0;
        for(int i = 0 ; i<=s.size();i++){
            ans = max(ans,dp[s.size()-1][i]);
        }
        return ans;
    }
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(),s.end());
        vector<vector<int>>dp(s.size()+2,vector<int>(s.size()+2,-1));
        int ans = solveTab(s);
        return ans;
    }
};