class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow=1,fast = 1;

        for(;fast<nums.size();fast++){
            if(nums[fast]==nums[fast-1]){
                continue;
            }
            else{
                nums[slow]=nums[fast];
                slow++;
            }
            
            
        }
        return slow;
    }
};