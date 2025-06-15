class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i = 0;i<nums.size() ;i++){
            mp[nums[i]]++;
        }  
        int ans =0;
        
        if(k>0){
            for(auto it:mp){
                if(mp.count(it.first+k)>0)ans++;

            }
            return ans;

        }else{
            for(auto it:mp){
                if(it.second>1){
                    ans++;
                }

            }
            return ans;
        }
        return ans;
    }
};