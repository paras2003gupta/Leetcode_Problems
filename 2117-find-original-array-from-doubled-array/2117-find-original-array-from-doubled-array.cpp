class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int>ans;
        int n = changed.size();

        if(n%2!=0){
            return ans;
        }
        map<int,int>mp;

        sort(changed.begin(),changed.end());
        for(auto it:changed){
            mp[it]++;
        }
        for(auto it:changed){
            if(mp.find(it)==mp.end()){
                continue;
            }else{
                mp[it]--;
                if(mp[it]==0){
                    ans.push_back(it);
                    mp.erase(it);
                }
                if(mp.find(2*it)==mp.end()){
                    return {};
                }else{
                    mp[2*it]--;
                    if(mp[2*it]==0){
                        mp.erase(2*it);
                    }
                }
            }
        }
        return ans;

    }
};