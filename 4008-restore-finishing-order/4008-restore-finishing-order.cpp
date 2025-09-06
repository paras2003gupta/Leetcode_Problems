class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_map<int,int>mp;
        for(auto it:friends){
            mp[it]++;
        }
        vector<int>ans;
        for(auto it:order){
            if(mp.find(it)!=mp.end()){
                ans.push_back(it);
            }
        }
        return ans;
    }
};