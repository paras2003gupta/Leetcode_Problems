class Solution {
public:
    long long ncr(int n , int r){
        long long ans = 1;
        for(long long i = 1; i<=min(n-r,r); i++){
            ans = (ans * (n-i+1))/i;
        }
        return ans;
    }
    int uniquePaths(int m, int n) {
        long long tot = m+n-2;

        return ncr(tot,m-1);
    }
};