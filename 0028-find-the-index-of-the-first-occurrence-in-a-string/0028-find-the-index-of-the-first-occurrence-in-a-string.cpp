class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int>lps(needle.size(),0);
        int n = needle.size();    
        int i = 1;
        int prevLps = 0;

        while(i<n){
            if(needle[i]==needle[prevLps]){
                
                prevLps++;
                lps[i] = prevLps;
                i++;
            }

            else if(prevLps==0){
                lps[i] = 0;
                i++;
            }
            else{
                prevLps = lps[prevLps-1];
            }
        }


        i = 0;
        int j = 0;

        while(i<haystack.size()){
            if(haystack[i] == needle[j]){
                i++;
                j++;
            }
            else if(j==0){
                i++;
            }
            else{
                j = lps[j-1];
            }

            if(j==needle.length()){
                return i-needle.length();
            }
        }
        return -1;

    }
};