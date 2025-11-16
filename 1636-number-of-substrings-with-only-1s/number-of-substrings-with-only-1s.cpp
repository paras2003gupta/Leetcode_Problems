class Solution {
public:
    const int mod = 1e9+7;
    int numSub(string s) {
        int i = 0 ;
        long long sum = 0;
        int n = s.size();
        
        long long len = 0;
        while(i<n){
            if(s[i]=='1'){
                len++;
                i++;
            }
            else{
                sum+=(((len%mod)*((len+1)%mod)%mod)/2)%mod;
                len = 0;
                i++;
            }
        }
        sum+=(((len%mod)*((len+1)%mod)%mod)/2)%mod;
        return sum;
        
    }
};