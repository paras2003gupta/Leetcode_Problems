class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int longest_sequential_prefix=nums[0];
        int n = nums.size();
        int i = 1;
        map<int,int>mp;
        mp[nums[0]]++;
        while(i<n&&nums[i-1]+1==nums[i]){
            mp[nums[i]]++;
            longest_sequential_prefix+=nums[i];
            i++;
        }
        while(i<n){
            mp[nums[i]]++;
            i++;
        }
        
        while(mp.find(longest_sequential_prefix)!=mp.end()){
            longest_sequential_prefix++;
        }
        return longest_sequential_prefix;

        
    }
};