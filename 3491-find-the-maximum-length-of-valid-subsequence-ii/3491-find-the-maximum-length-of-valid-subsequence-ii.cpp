#include <vector>
#include <algorithm>

class Solution {
public:
    /**
     * @brief Finds the maximum length of a valid subsequence using dynamic programming.
     * @param nums The input vector of integers.
     * @param k The positive integer for the modulo operation.
     * @return The length of the longest valid subsequence.
     *
     * The state dp[i][j] stores the length of the longest valid subsequence
     * ending with remainder i, whose previous element had remainder j.
     */
    int maximumLength(std::vector<int>& nums, int k) {
        // dp[ending_rem][previous_rem]
        std::vector<std::vector<int>> dp(k, std::vector<int>(k, 0));
        int max_len = 0;

        // O(n * k)
        for (int num : nums) {
            int r_curr = num % k;
            for (int r_prev = 0; r_prev < k; ++r_prev) {
                // A sequence ending in r_prev (with r_curr before it) can be
                // extended by the current number (with remainder r_curr).
                // The new sequence ends in r_curr, with r_prev before it.
                dp[r_curr][r_prev] = dp[r_prev][r_curr] + 1;
                
                // Update the overall maximum length found so far.
                max_len = std::max(max_len, dp[r_curr][r_prev]);
            }
        }
        
        return max_len;
    }
};