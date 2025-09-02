class Solution {
public:
    vector<int>lpsarray(string pattern){
        int m = pattern.size();
        vector<int>lps(m,0);
        int len = 0;
        int i = 1;
        while(i<m){
            if(pattern[i]==pattern[len]){
                len+=1;
                lps[i] = len;
                i++;
            }
            else{
                if(len!=0){
                    len = lps[len-1];
                }else{
                    lps[i]  =0;
                    i++;
                }
            }
        }
        return lps;
    }
    string longestPrefix(string s) {
        vector<int>lpsarr = lpsarray(s);

        int len = lpsarr[s.size()-1];
        string ans ="";
        for(int i = 0;i<len ; i++){
            ans+=s[i];
        }
        return ans;
    }
};