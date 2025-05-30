class Solution {
    private:
    bool solve(string &s , string &p , int i , int j,vector<vector<int>>&dp){
        if(i<0&&j<0)return true;
        if(i<0&&j>=0)return false;
        if(i>=0&&j<0){
            for(int k = 0 ; k<=i ; k++){
                if(p[k]!='*'){
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j]!=-1)return dp[i][j];

        if(s[j]==p[i]||p[i]=='?'){
            return dp[i][j]= solve(s,p,i-1,j-1,dp);
        }
        else if(p[i]=='*'){
            return dp[i][j]= solve(s,p,i-1,j,dp)||solve(s,p,i,j-1,dp);
        }
        else{
            return dp[i][j]= false;
        }
    }

public:
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(p.size()+1,vector<int>(s.size()+1,-1));
        return solve(s,p,p.size()-1,s.size()-1,dp);
    }
};