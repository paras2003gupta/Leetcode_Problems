class Solution {
public:
    int solve(vector<int>&jd,int n, int idx , int d,vector<vector<int>>&dp){
        if(d==1){ // if only one day left then we hv to do all jobs in single day and retur all our jobs;

            int maxD = INT_MIN;
            for(int i = idx ; i<n ; i++){
                maxD = max(maxD,jd[i]);
            }
            return maxD;
        }
        if(dp[idx][d]!=-1)return dp[idx][d];
        int maxD = jd[idx];
        int finalRes = INT_MAX;
        for(int i = idx ; i<=n-d ; i++){
            maxD = max(maxD,jd[i]);

            finalRes = min(finalRes,maxD+solve(jd,n,i+1,d-1,dp));
        }
        return dp[idx][d]= finalRes;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n<d){
            return -1;
        }
        vector<vector<int>>dp(n+1,vector<int>(d+1,-1));
            return solve(jobDifficulty,n,0,d,dp);
    }
};