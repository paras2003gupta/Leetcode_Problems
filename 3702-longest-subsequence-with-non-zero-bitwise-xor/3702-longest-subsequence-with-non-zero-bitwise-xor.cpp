class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr = 0;
        int t = 0;
        for(auto it:nums){
    xr^=it;
            if(it!=0)t=it;
        }
        if(xr==0&&t==0){
            return 0;
        }
        if(xr==0){
            return nums.size()-1;
        }
        else{
            return nums.size();
        }
    }
};