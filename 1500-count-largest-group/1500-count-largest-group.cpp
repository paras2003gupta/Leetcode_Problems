class Solution {
    private:
    int sumOfDigits(int n){
        string s = to_string(n);
        int sum = 0;
        for(auto it:s){
            sum+=(it-'0');
        }
        return sum;
    }
public:
    int countLargestGroup(int n) {
        unordered_map<int,int>mp;
        for(int i = 1;i<=n ; i++){
            mp[sumOfDigits(i)]++;
        }
        int maxsize = INT_MIN;
        for(auto it:mp){
           maxsize = max(maxsize,it.second);
        }
        int cnt = 0;
        for(auto it:mp){
            if(it.second==maxsize){
                cnt++;
            }
        }
        return cnt;
    }
};