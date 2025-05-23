class Solution {
    private:
    
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long int ans = 0;
        int n = nums.size();
        int balikabakra = INT_MAX;
        int sum =0;
        for(int i = 0;i<n ; i++){
            if((nums[i]^k)>nums[i]){
                ans+=nums[i]^k;
                sum++;
                balikabakra = min(balikabakra,abs((nums[i]^k)-nums[i]));
            }
            else{
                ans+=nums[i];
                balikabakra = min(balikabakra,abs((nums[i]^k)-nums[i]));
            }
        }
        if(sum%2==0){
            return ans;
        }else{
            return ans-balikabakra;
        }
        
        
        return ans;


    }
};