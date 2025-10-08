class Solution {
public:
    bool ispal(string s){
        int j = s.size()-1;
        int i = 0;
        while(i<=j){
            if(s[i++]!=s[j--]){
                return false;
            }
            
        }
        return true;

    }
    bool isPalindrome(string s) {
        string ans = "";
        for(auto it:s){
            if(isalnum(it)){
                ans+=tolower(it);
            }
        }
        return ispal(ans);
    }
};