class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int mini = INT_MAX;
        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[low]<=nums[mid]){
                //left sorted
                if(nums[mid]>=nums[high]){
                    //left sorted but element is present on right side
                    low = mid+1;
                    mini = min(mini,nums[mid]);
                }
                else{

                    high = mid-1;
                    mini  = min(mini,nums[low]);
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