class Solution {
public:
    int countTriples(int n) {
        int ans =0;
        for(int i = 1;i<=n ; i++){
            for(int j = 1 ; j<=n ; j++ ){
                if(i!=j){
                    int a = i*i + j*j;
                    double c  = sqrt(a);
                    int t = sqrt(a);
                    if(i*i+j*j == c*c&&c!=i && c!=j&&t==c&&c<=n){
                        ans++;
                    } 
                }
            }
        }
        return ans;
    }
};