class Solution {
using ld = long double;
using ll = long long;
public:
    bool solve(vector<int>&nums,long long tar, int i,ld maketar,ld t){
        if(tar==1&&maketar==t&&i==nums.size()){
            return true;
        }
        if(i==nums.size()){
            return false;
        }
        bool take = false;
        if(tar%nums[i]==0){
            take = solve(nums,tar/nums[i],i+1,maketar,t);
        }
        
        bool nottake = solve(nums,tar,i+1,maketar*nums[i],t);

        return take||nottake;
    }
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        if(target==1){
            return false;
        }
       return solve(nums,target,0,1,target);
    }
};