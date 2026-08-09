class Solution {
public:
    int n;
    int dp[101][101];

    int helper(vector<int>& piles, int i, int M) {
        if (i >= n) return 0;
        if (dp[i][M] != -1) return dp[i][M];
        
        int stones = 0;
        int result = 0;
        int totalStones = 0;
        
        for (int k = i; k < n; k++) {
            totalStones += piles[k];
        }
        
        for (int x = 1; x <= 2 * M && i + x <= n; x++) {
            stones += piles[i + x - 1];
            result = max(result, totalStones - helper(piles, i + x, max(M, x)));
        }
        
        return dp[i][M] = result;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(dp, -1, sizeof(dp));
        return helper(piles, 0, 1);
    }
};
