class Solution {
public:
    int solve(int e , int f, vector<vector<int>>& dp) {
        if (e == 1) return f;
        if (f == 0 || f == 1) return f;
        if (dp[e][f] != -1) return dp[e][f];

        int low = 1, high = f, mn = INT_MAX;
        while (low <= high) {
            int mid = (low + high) / 2;

            int ans1 = (dp[e-1][mid-1] != -1) ? dp[e-1][mid-1] : solve(e-1, mid-1, dp);
            int ans2 = (dp[e][f-mid] != -1) ? dp[e][f-mid] : solve(e, f-mid, dp);

            int temp = 1 + max(ans1, ans2);
            mn = min(mn, temp);

            // Move binary search depending on which side is worse
            if (ans1 < ans2) {
                low = mid + 1; // need more floors
            } else {
                high = mid - 1; // fewer floors
            }
        }
        return dp[e][f] = mn;
    }

    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1, vector<int>(n+1, -1));
        return solve(k, n, dp);
    }
};
