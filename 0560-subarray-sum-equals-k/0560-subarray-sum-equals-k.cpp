class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mp;
        mp[0] = 1;
        int n = nums.size();
        vector<int>prefix(n+1,0);
        for(int i = 0;i<n ;i++){
            prefix[i+1]+=prefix[i]+nums[i];
        }
        int cnt =0;
        for(int i = 1 ; i<n+1 ; i++){
            auto it =  mp.find(prefix[i]-k);
            bool seen = true;
            if(it==mp.end()) seen=false;
            if(seen){
                cnt+=mp[prefix[i]-k];
            }
            mp[prefix[i]]++;
        }
        return cnt;

    }

};