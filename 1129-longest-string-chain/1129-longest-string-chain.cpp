class Solution {
private:
bool checkOneLetterDiff(string &a , string &b){
    if(a.size()-1!=b.size()) return false;
    int second = 0;
    int first = 0;
    while(first<a.size()){
       if(a[first]==b[second]){
        first++;second++;
       }else{
        first++;
       }
    }
    return first==a.size()&&second==b.size();
}
static bool cmp(string &a, string &b){
    return a.size()<b.size();
}
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        int n = words.size();
        vector<int>dp(n,1);
        int maxi= INT_MIN;
        for(int i = 0 ; i< n ; i++){
           
            for(int prev = 0 ; prev<i ; prev++){
                if(checkOneLetterDiff(words[i],words[prev])&&dp[i]<dp[prev]+1){
                    dp[i] = dp[prev]+1;
                }
            }
            maxi = max(maxi,dp[i]);

        }
        
        return maxi;
    }
};