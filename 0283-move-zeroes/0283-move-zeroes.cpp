class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        while(i<n&&nums[i]!=0){
            i++;
        }
        j = i;
        while(j<n){
            while(j<n&&nums[j]==0){
                j++;
            }

            if(i<n&&j<n){swap(nums[i],nums[j]);
                j++;
                i++;
            }}

        }
    
};