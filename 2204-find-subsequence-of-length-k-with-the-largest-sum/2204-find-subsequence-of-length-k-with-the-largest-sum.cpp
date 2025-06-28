class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int>ans;
        int n = nums.size();
        vector<pair<int,int>>v;
        for(int i = 0;i<n ;i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());

        vector<pair<int,int>>ans2;
        for(int i= 0;i<k ;i++){
            ans2.push_back({v[i].second,v[i].first});
        }
        sort(ans2.begin(),ans2.end());
        for(auto it:ans2){
            ans.push_back(it.second);
        }
        return ans;


    }
};