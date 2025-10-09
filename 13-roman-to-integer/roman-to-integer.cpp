class Solution {
public:
    unordered_map<char,int>mp;
    
    int romanToInt(string s) {
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int n = s.size();
        long long ans = 0;
        int i = 0;
        for(;i< n-1 ; i++){
            if(mp[s[i]]>mp[s[i+1]]){
                ans+=mp[s[i]];
            }
            else if(mp[s[i]]==mp[s[i+1]]){
                ans+=2*mp[s[i]];
                i++;
            }
            else{
                ans+=(mp[s[i+1]]-mp[s[i]]);
                i++;
            }
        }
        if(i==n-1){
            ans+=mp[s[i]];
        }
        return ans;
        
    }
};