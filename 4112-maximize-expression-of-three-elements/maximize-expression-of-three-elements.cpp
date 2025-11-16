class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = nums[nums.size()-1]+nums[nums.size()-2]-nums[0];
        return ans;
    }
};