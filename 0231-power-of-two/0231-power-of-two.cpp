class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0){
            return false;
        }
        long long ans = n;
        if(ans<0){
           return false;
        }
        
        if((ans&(ans-1))==0){
            return true;
        }
        return false;
        
        
    }
};