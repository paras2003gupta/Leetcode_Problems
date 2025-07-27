class Solution {
    private:
    vector<int> filter(vector<int>nums){
        int n = nums.size();
        vector<int>Ans;
        Ans.push_back(nums[0]);
        for(int i  = 1 ;i<n ;i++){
            if(nums[i]==nums[i-1]){
                continue;
            }
            Ans.push_back(nums[i]);
        }
        return Ans;
    }
public:
    int countHillValley(vector<int>& nums) {
        int cnt = 0;
        vector<int>f = filter(nums);
        nums = f;
        
        int n = nums.size();
        
        for(int i = 1;i<n-1 ; i++){
            if(nums[i]==nums[i-1]){
                continue;
            }

            if(nums[i]>nums[i-1]&&nums[i]>nums[i+1]){
                cnt++;
                continue;
            }

            if(nums[i]<nums[i-1]&&nums[i]<nums[i+1]){
                cnt++;
                continue;
            }
            
        }
        return cnt;
    }
};