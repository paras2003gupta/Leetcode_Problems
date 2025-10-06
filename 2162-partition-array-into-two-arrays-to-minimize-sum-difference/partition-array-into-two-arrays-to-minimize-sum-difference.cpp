class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for (int x : nums) {
            totalSum += x;
        }

        // 1. Generate sums for the left half
        vector<vector<int>> left_sums = generate_sums(nums, 0, n / 2);

        // 2. Generate sums for the right half
        vector<vector<int>> right_sums = generate_sums(nums, n / 2, n);

        int min_diff = INT_MAX;

        // 3. Find the optimal combination
        for (int k = 0; k <= n / 2; ++k) {
            // Sort the sums for the right partition to enable binary search
            sort(right_sums[n / 2 - k].begin(), right_sums[n / 2 - k].end());

            for (int sum1 : left_sums[k]) {
                int target = (totalSum / 2) - sum1;

                // Use binary search (lower_bound) on the corresponding right_sums
                auto it = lower_bound(right_sums[n / 2 - k].begin(), right_sums[n / 2 - k].end(), target);

                // Check the found element and the one before it
                if (it != right_sums[n / 2 - k].end()) {
                    int current_sum = sum1 + *it;
                    min_diff = min(min_diff, abs(totalSum - 2 * current_sum));
                }
                if (it != right_sums[n / 2 - k].begin()) {
                    it--;
                    int current_sum = sum1 + *it;
                    min_diff = min(min_diff, abs(totalSum - 2 * current_sum));
                }
            }
        }
        return min_diff;
    }

    // Helper function to generate all subset sums
    vector<vector<int>> generate_sums(const vector<int>& nums, int start, int end) {
        int len = end - start;
        vector<vector<int>> sums(len + 1);
        for (int i = 0; i < (1 << len); ++i) {
            int current_sum = 0;
            int num_elements = 0;
            for (int j = 0; j < len; ++j) {
                if ((i >> j) & 1) {
                    current_sum += nums[start + j];
                    num_elements++;
                }
            }
            sums[num_elements].push_back(current_sum);
        }
        return sums;
    }
};