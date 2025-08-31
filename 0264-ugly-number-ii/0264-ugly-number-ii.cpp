class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n+1,0);
        dp[1] = 1;

        int i2,i3,i5;
        i2= 1;
        i3= 1;
        i5 = 1;
        //1st ugly  number
        for(int i = 2 ; i<= n ;i++){
            int i2UglyNum = dp[i2]*2;
            int i3UglyNum = dp[i3]*3;
            int i5UglyNum = dp[i5]*5;
            int minUglyNum = min({i2UglyNum,i3UglyNum,i5UglyNum});
            dp[i] = minUglyNum;
            if(minUglyNum==i2UglyNum){
                i2++;
            }
            if(minUglyNum==i3UglyNum){
                i3++;
            }
            if(minUglyNum==i5UglyNum){
                i5++;
            }
        }


        return dp[n];
    }
};