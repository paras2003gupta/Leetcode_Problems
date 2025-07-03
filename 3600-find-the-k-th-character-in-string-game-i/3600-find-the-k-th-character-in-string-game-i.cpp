class Solution {
public:
    char kthCharacter(int k) {
        string ans = "a";

        while(ans.size()<=k+1){
            string s;
            for(auto it:ans){
                s.push_back(it+1);
            }
            ans+=s;
        }
        return ans[k-1];
    }
};