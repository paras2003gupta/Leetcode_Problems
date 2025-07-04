class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int>res;
        for(int i = 0;i<nums.size(); i++){
            int t= abs(nums[i]);
            if(nums[t-1]<0){
                res.push_back(t);
            }
            nums[t-1]*=-1;

        }
        return res.back();



    }
};