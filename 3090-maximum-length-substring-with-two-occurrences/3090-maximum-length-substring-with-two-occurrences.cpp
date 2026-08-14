class Solution {
public:
    int freqGreaterThan2(vector<int>&freq){
        for(auto it:freq){
            if(it>2){
                return true;
            }
        }
        return false;
    }
    int maximumLengthSubstring(string s) {
        int i = 0;int j = 0;
        vector<int>freq(26,0);
        int n = s.size();
        int maxsize = 0;
        while(j<n){
            char ch = s[j];
            freq[ch-'a']++;

            while(freqGreaterThan2(freq)&&i<=j){
                freq[s[i]-'a']--;
                i++;
            }
            maxsize = max(maxsize,j-i+1);

            j++;
        }
        return maxsize;
    }
};