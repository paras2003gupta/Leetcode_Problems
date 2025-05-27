class Solution {
public:
    int differenceOfSums(int n, int m) {
        if(n==1){

        }
        int sum  =(n*(n+1))/2;
        if(m<=n){
            for(int i = 1;i*m<=n ; i++){
                sum-=2*(m*i);
            }
        }
        return sum;
        
    }
};