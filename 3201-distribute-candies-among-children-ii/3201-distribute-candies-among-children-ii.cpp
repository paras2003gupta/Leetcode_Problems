class Solution {
public:
    long long distributeCandies(int n, int limit) {
        if(limit*3>=n){
            long long cnt = 0;
            for(int i = 0;i<=min(n,limit) ; i++){
               cnt+= max(min(limit, n - i) - max(0, n - i - limit) + 1, 0);
            }
            return cnt;

        }else{
            return 0;
        }
    }
};