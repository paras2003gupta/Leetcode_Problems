class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>next_greater(n);
        int maxi = -1;
        int max_diff = -1;
        for(int i = n-1; i>=0 ; i--){
            next_greater[i] = maxi;
            maxi = max(maxi,nums[i]);
        }

        for(int i = 0;i<n ; i++){
            if(next_greater[i]>nums[i]){
                int diff = next_greater[i]-nums[i];
                max_diff = max(max_diff,diff);
            }
        }
        return max_diff;
        
    }
};