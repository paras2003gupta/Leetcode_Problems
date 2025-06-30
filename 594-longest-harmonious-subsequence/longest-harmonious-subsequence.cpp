class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        int maxi  =0;

        for(auto it:mp){
            
            int ans = it.second;
            if(mp.find(it.first+1)!=mp.end()){
                auto k = mp[it.first+1];
                ans+=k;
                maxi = max(maxi,ans);
            }
        }
        return maxi;
    }
};