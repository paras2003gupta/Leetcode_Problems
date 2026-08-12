class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left = 0, ans = 0;
        unordered_map<int,int> cnt;

    for (int right = 0; right < nums.size(); right++) {
        cnt[nums[right]]++;

        while (cnt[nums[right]] > k) {
        cnt[nums[left]]--;
        left++;
    }

    ans = max(ans, right - left + 1);
}
return ans;
    }
};