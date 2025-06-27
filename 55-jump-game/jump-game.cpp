class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxjump = nums[0];
        int n = nums.size();
        for(int i = 1; i<nums.size(); i++){
            if(maxjump>=i){
                maxjump = max(maxjump,i+nums[i]);
            }
           
        }
        return maxjump>=n-1;
    }
};