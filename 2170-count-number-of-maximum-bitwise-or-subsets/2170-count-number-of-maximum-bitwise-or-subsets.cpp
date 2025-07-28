class Solution {
    int maxor;
    int solve(int i, vector<int>&nums,int currOr){
        if(i==nums.size()){
            return (currOr==maxor)?1:0;
        }

        int take = solve(i+1,nums,currOr|nums[i]);

        int nottake = solve(i+1,nums,currOr);

        return take+nottake;

    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        maxor = 0;
        for(auto it:nums){
            maxor|=it;
        }
        
        int ans = solve(0,nums,0);
        return ans;
    }
};