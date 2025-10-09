class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int mini = INT_MAX;
        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[low]<=nums[mid]){
                mini = min(mini,nums[mid]);
                if(nums[mid]>=nums[high]){
                    //left sorted but element is present on right side
                    low = mid+1;
                    
                }
                else{
                    high = mid-1;
                }
            }
            else{
                //right sorted
                mini = min(mini,nums[mid]);
                high = mid-1;
            }
        }
        return mini;
    }
};