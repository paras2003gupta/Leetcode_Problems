class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        string ans= "";
        ans+=s[0];
        
        ans+=s[1];
        if(s.size()<=2){
            return s;
        }
        for(int i = 2;i<n ;i++){
            if(s[i]==s[i-2]&&s[i]==s[i-1]){
                continue;
            }
            ans+=s[i];
        }
        return ans;
    }
};