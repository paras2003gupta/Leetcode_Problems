class Solution {
    #define MOD 1000000007
public:
    int countPermutations(vector<int>& complexity) {
        long long ans = 1;
        for(int i = 1  ; i<complexity.size() ;i++){
            if(complexity[i]<=complexity[0]){
                return 0;
            }
            ans= ((ans%MOD)*(i%MOD))%MOD;
        }
        return ans%MOD;
    }
};