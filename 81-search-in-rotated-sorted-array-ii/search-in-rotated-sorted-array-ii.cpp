class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;

        while(high>=low){
            int mid = (low) + (high-low)/2;
            if(nums[mid]==target){
                return true;

            }

            if(nums[low]==nums[mid]&&nums[mid]==nums[high]){
                low++;
                high--;
                continue;
            }

            if(nums[mid]<=nums[high]){
                //right part is sorted
                if(nums[high] >= target&&nums[mid]<target){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }

            }

            else{
                //left part is sorted;
                if(nums[mid]>target&&target>=nums[low]){
                    high = mid-1;
                }
                else{
                    low = mid + 1;
                }
            }
        }
        return false;
    }
};