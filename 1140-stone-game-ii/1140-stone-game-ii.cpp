class Solution {
public:
    int n ;
    int dp[2][101][101];
    int solve(vector<int>&piles , int person , int i , int M){
        if(i>=n){
            return 0;
        }
        if(dp[person][i][M]!=-1)return dp[person][i][M];
        int stones = 0;
        int ans = person==1?-1:INT_MAX;
        if(person==1){
            for(int x = 1;x<=2*M&&(i+x-1<n); x++){
                stones+=piles[i+x-1];
                ans = max(ans,stones + solve(piles,0, i+x ,max(M,x)));
            }
        }
        else{
            for(int x = 1 ;x<=2*M&&(i+x-1<n) ; x++){
                ans = min(ans,solve(piles,1,i+x,max(M,x)));
            }
        }
        return dp[person][i][M]= ans;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(dp,-1,sizeof(dp));
        return solve(piles,1,0,1);
    }
};