class Solution {
    using ll = long long ;
    using ld  = long double;
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n = nums.size();
        for(int mask = 1; mask< (1<<n )-2 ; mask++){
            ld prod_0= 1,prod_1 = 1;
            for(int i = 0;i<n ; i++){
                if(mask&(1<<i)){
                    prod_1*=nums[i];
                }
                else{
                    prod_0*=nums[i];
                }
                if(prod_0>target||prod_1>target){
                    break;
                }
            }
            if(prod_0==target&&prod_1==target){
                return true;
            }
        }
        return false;
    }
};