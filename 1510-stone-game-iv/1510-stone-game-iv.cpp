class Solution {
public:
    vector<vector<int>>dp;
    bool AliceTurn(int n,int turn){
    if (n == 0) {
        if (turn == 1)
            return false;   // Alice's turn, but no stones => Alice loses.
        else
            return true;    // Bob's turn, but no stones => Bob loses, so Alice wins.
    }
        if(dp[n][turn]!=-1)return dp[n][turn];
        int ans = pow(n,0.5);
        if(turn==1){
            bool alice = false;
            for(int i = 1; i<=ans ; i++){
                alice = alice || (AliceTurn(n-(i*i),0));
            }
            return dp[n][turn]= alice;
        }
        else {
            bool alice = true;
            for(int i = 1 ; i<= ans ; i++){
                alice = alice && (AliceTurn(n-(i*i),1));
            }
            return dp[n][turn]= alice;
        }
        return false;



    }
    bool winnerSquareGame(int n) {
        dp = vector<vector<int>>(n+1,vector<int>(2,-1));
        return AliceTurn(n,1);
    }
};