class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>fq1(26,0);
        vector<int>fq2(26,0);

        for(auto it:s){
            fq1[it-'a']++;
        }
        for(auto bt : t){
            fq2[bt-'a']++;
        }
        return fq1==fq2;
    }
};