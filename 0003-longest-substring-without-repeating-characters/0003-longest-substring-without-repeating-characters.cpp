class Solution {
public:
    int lengthOfLongestSubstring(string st) {
        int s = 0;
        int e = -1;
        int ans = 0;
        int n = st.size();
        map<char,int>mp;
        while(e<n){
            if(s>e){
                e++;
                mp[st[e]]++;
                continue;
            }
            if(e==n-1){
                ans = max(ans,e-s+1);
                if(s==n-1)break;
                mp[st[s]]--;
                s++;

                continue;
            }
            //can we expand
            if(mp[st[e+1]]==0){
                e++;
                
                mp[st[e]]++;
                continue;
            }else{
                ans = max(ans,e-s+1);
                mp[st[s]]--;
                s++;
            }

        }
        return ans;
    }
};