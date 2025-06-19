class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i = 0;
        int ans = 0;
        while(i<nums.size()){
            int j = upper_bound(nums.begin(),nums.end(),nums[i]+k)-nums.begin()-1;
            ans++;
            i = j+1;

        }
        return ans;
    }
};