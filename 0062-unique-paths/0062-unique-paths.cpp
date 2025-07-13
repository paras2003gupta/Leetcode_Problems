class Solution {
public:
    int ncr(int n , int r){
        int ans = 1;
        for(int i = 1; i<=min(n-r,r); i++){
            ans = (ans * (n-i+1))/i;
        }
        return ans;
    }
    int uniquePaths(int m, int n) {
        int tot = m+n-2;

        return ncr(tot,m-1);
    }
};