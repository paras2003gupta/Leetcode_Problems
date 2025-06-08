class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        vector<stack<int>>cnt(26);

        for(int i = 0;i<n ; i++){
            if(s[i]!='*'){
                cnt[s[i]-'a'].push(i);
            }else{
                for(int j = 0;j<26 ; j++){
                    if(!cnt[j].empty()){
                        cnt[j].pop();
                        break;
                    }
                }
            }
            
        }
        vector<char>ans(n,'*');
        for(int i = 0;i<26 ; i++){
            while(!cnt[i].empty()){
                int idx = cnt[i].top();
                cnt[i].pop();
                char c = i+'a';
                ans[idx] = c;
            }
        }
        string k = "";
        for(auto it:ans){
            if(it!='*'){
                k+=it;
            }
        }
        return k;
    }
};