class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        for(int i = nums[0]+1 ; i<=nums[nums.size()-1]; i++){
            int idx = lower_bound(nums.begin(),nums.end(),i)-nums.begin();
            if(nums[idx]!=i){
                ans.push_back(i);
            }
        }
        return ans;
    }
};