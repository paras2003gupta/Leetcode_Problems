class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero_tracker=0,fwd_ptr=0;
        while(zero_tracker<nums.size()&&nums[zero_tracker]!=0){
            zero_tracker++;
        }
        if(zero_tracker==nums.size()){
            return;
        }
        for(int i = zero_tracker+1 ; i < nums.size();i++){
            if(nums[i]!=0){
                swap(nums[i],nums[zero_tracker]);
                while(zero_tracker<nums.size()&&nums[zero_tracker]!=0){
                    zero_tracker++;
                }
            }
        }

    }
};