class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        priority_queue<pair<char,int>,vector<pair<char,int>>,greater<pair<char,int>>>pq;
        for(int i = 0;i<n ; i++){
            if(s[i]!='*'){
                pq.push({s[i],-i});
            }else{
                pq.pop();
            }
        }
        vector<char>str(n,'*');
        while(!pq.empty()){
            char c = pq.top().first;
            int ind = -pq.top().second;
            str[ind] = c;
            pq.pop();
        }
        string ans = "";
        for(auto it:str){
            if(it!='*'){
                ans+=it;
            }
        }
        return ans;
    }
};