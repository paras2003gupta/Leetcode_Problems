class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int i = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int j = lower_bound(nums.begin(), nums.end(), target + 1) - nums.begin() - 1;

        if (i < n && nums[i] == target) {
            return {i, j};
        }
        return {-1, -1};
    }
};
