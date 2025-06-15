class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        set<pair<int,int>>st;
        int cnt = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            if(mp.find(nums[i]-k)!=mp.end()){
                int a = max(nums[i]-k,nums[i]);
                int b = min(nums[i]-k,nums[i]);
                st.insert({a,b});
                cout<<nums[i]-k<<" "<<nums[i]<<" "<<i<<endl;
            }
            if(mp.find(nums[i]+k)!=mp.end()){
                int a = max(nums[i]+k,nums[i]);
                int b = min(nums[i]+k,nums[i]);
                st.insert({a,b});
                cout<<k+nums[i]<<" "<<nums[i]<<" "<<i<<endl;
            }

            mp[nums[i]]++;
        }
        return st.size();
    }
};