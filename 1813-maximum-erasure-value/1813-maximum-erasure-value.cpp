class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        int i = 0;
        int j = 0;
        map<int,int>mp;
        int minsum = INT_MIN;
        int temp = 0;
        while(j<n){
            
            while(i<=j&&mp.find(nums[j])!=mp.end()){
                mp[nums[i]]--;
                if(mp[nums[i]]==0)mp.erase(nums[i]);
                minsum = max(minsum,temp);
                temp -= nums[i];
                i++;
            }
            temp+=nums[j];
            mp[nums[j]]++;
            j++;
            

        }
        minsum = max(minsum,temp);

        return minsum;
    }
};