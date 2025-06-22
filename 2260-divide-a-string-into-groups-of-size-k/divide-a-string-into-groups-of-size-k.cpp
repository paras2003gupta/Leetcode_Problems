class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;
        int n = s.size();
        string ch = "";
        for(int i = 0;i<min(n,k) ; i++){
            ch+=s[i];
        }
        while(ch.size()<k){
            ch+=fill;
        }
        ans.push_back(ch);
        if(k>n){
            return ans;
        }
        ch = "";
        for(int i = k ; i<n ;i++){
            ch+=s[i];
            if(ch.size()==k){
                ans.push_back(ch);
                ch = "";
            }
            
        }
        while(ch.size()<k&&ch.size()!=0){
            ch+=fill;
        }
        if(ch.size()==k)
        ans.push_back(ch);
        
        return ans;
    }
};