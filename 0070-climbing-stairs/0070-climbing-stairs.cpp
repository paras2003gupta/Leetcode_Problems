class Solution {
public:
    int climbStairs(int n) {
        if(n==1)return 1;
        int prev0 =1;
        int prev1 = 2;
        for(int i = 3; i<=n ; i++){
            int temp = prev1;

            prev1 = prev1+prev0;
            prev0 = temp;

        }
        return prev1;
    }
};