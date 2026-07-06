class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left =0,right=0;
        int sum= 0;
        int min_size=nums.size();
        while(right<nums.size()&&sum<target){
            sum+=nums[right];
            while(sum>=target&&left<=right){
                min_size=min(min_size,right-left+1);
                sum-=nums[left];
                left++;
            }
            right++;
        }
        if(min_size==nums.size()){
            if(accumulate(nums.begin(),nums.end(),0)>=target){
                return min_size;
            }else{
                return 0;
            }
        }
        return min_size;
    }
};