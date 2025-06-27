class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        long long curr_sum = 0;
        long long min_sum = 0;
        long long n = nums.size();
        long long total_sum = 0;
        for(long long i = 0; i<nums.size() ; i++){
            total_sum+=nums[i];
            curr_sum+=nums[i];
            min_sum = min(min_sum,curr_sum);
            if(curr_sum>0){
                curr_sum = 0;
            }
        }
        curr_sum = 0;
        long long max_sum = -1e18;

        for(long long i  = 0;i<n ; i++){
            curr_sum+=nums[i];
            max_sum = max(max_sum,curr_sum);
            if(curr_sum<0){
                curr_sum = 0;
            }
        }
        if(max_sum<0){
            return max_sum;
        }
        else{
            return max(total_sum-min_sum,max_sum);
        }
    }
};