class Solution {
public:
    string process(string s){
        int i = 0 ; 
        int j = 0;
        string ans = "";
        while(j<s.size()){
            if(s[i]==s[j]){
                j++;
            }
            else{
                int len = j-i;
                ans+=to_string(len);
                ans+=s[i];
                i = j;
            }
        }
        int len = j-i;
        ans+=to_string(len);
        ans+=s[i];
        i = j;
        return ans;
    }
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }

        string ans = countAndSay(n-1);

        string pr = process(ans);
        //processing ans
        return pr;
    }
};