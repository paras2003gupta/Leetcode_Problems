class Solution {
private:
bool isPal(string &s, int i, int j){
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

int solve(int i , string s,vector<int>&dp){
    if(i==s.size()) return 0;
    if(dp[i]!=-1)return dp[i];
    int mini = INT_MAX;
    for(int j = i; j<s.size() ; j++){
        
        if(isPal(s,i,j)){
            int k = 1+solve(j+1,s,dp);
            mini = min(mini,k);
        }
    }
    return dp[i]=mini;
}
public:
    int minCut(string s) {
        if(isPal(s,0,s.size()-1)) return 0;
        vector<int>dp(s.size(),-1);
        return solve(0,s,dp)-1;
    }
};