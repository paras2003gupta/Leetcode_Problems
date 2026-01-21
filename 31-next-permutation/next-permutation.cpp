class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // 1. Find the first decreasing element from the right
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // 2. If no such element is found, the array is in descending order
        if (i >= 0) {
            int j = n - 1;
            // 3. Find the element just larger than nums[i]
            while (nums[j] <= nums[i]) {
                j--;
            }
            // 4. Swap them
            swap(nums[i], nums[j]);
        }

        // 5. Reverse the elements to the right of index i
        // Using reverse is more efficient than sort (O(n) vs O(n log n))
        reverse(nums.begin() + i + 1, nums.end());
    }
};