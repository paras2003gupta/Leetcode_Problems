class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int i = 0;
        int cnt_maxi  = 0;
        long long cnt = 0;
        int n = nums.size();
        int j = 0;
        int maxi = *max_element(nums.begin(),nums.end());
        while(j<n&&i<=j){
            if(nums[j]==maxi){
                cnt_maxi++;
            }
            while(cnt_maxi>=k){
                cnt+=(n-j);
                if(nums[i]==maxi){
                    cnt_maxi--;
                }
                i++;
                
            }
            j++;

        }
        return cnt;
    }
};