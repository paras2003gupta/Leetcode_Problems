class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int>mp;
        if(s.size()<=10){
            return {};
        }
        string win = "";
        for(int i =  0 ;i<10 ; i++){
            win+=s[i];
        }
        mp[win]++;
        for(int i = 10;i<s.size() ; i++){
            win = win.substr(1);
            win+=s[i];
            mp[win]++;
        }
        vector<string>ans;
        for(auto it:mp){
            if(it.second>1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};