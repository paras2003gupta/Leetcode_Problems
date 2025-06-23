class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<int>>mp;
        for(int i= 0;i<strs.size() ; i++){
            string k = strs[i];
            sort(k.begin(),k.end());
            mp[k].push_back(i);
        }
        vector<vector<string>>ans;
        for(auto it:mp){
            vector<string>temp;
            for(auto k:it.second){
                temp.push_back(strs[k]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};