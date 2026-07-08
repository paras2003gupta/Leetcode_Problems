class Solution {
public:
    int characterReplacement(string s, int k) {
        int l =0,r=0;
        int n = s.size();
        int maxfq = 0;
        int maxlen=0;
        vector<int>arr(26,0);

        while(r<n){
            arr[s[r]-'A']++;
            maxfq = max(maxfq,arr[s[r]-'A']);
            while((r-l+1)-maxfq>k){
                arr[s[l++]-'A']--;
            }
            if((r-l+1)-maxfq<=k){
                maxlen= max(maxlen,(r-l+1));
            }
            r++;


        }
        return maxlen;

    }
};